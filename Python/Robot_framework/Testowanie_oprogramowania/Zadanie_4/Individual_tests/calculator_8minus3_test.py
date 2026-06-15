import unittest
import time
from appium import webdriver
from appium.options.android import UiAutomator2Options
from appium.webdriver.common.appiumby import AppiumBy
from selenium.common.exceptions import NoSuchElementException, TimeoutException
from selenium.webdriver.support.ui import WebDriverWait

appium_server_url = "http://localhost:4723"
calculator_package = "com.google.android.calculator"

capabilities = {
    "platformName": "Android",
    "automationName": "uiautomator2",
    "deviceName": "Android",
    "appPackage": calculator_package,
    "appActivity": "com.android.calculator2.Calculator",
    "noReset": True,
    "newCommandTimeout": 60,
}

class TestGoogleCalculator8Minus3(unittest.TestCase):
    def setUp(self) -> None:
        options = UiAutomator2Options().load_capabilities(capabilities)
        self.driver = webdriver.Remote(appium_server_url, options=options)
        self.driver.update_settings({"ignoreUnimportantViews": False})
        self.wait = WebDriverWait(self.driver, 5)

    def tearDown(self) -> None:
        if self.driver:
            self.driver.quit()

    def test_eight_minus_three_equals_five(self) -> None:
        # Force restart calculator to ensure it's in the foreground
        self.driver.terminate_app(calculator_package)
        self.driver.activate_app(calculator_package)
        time.sleep(2)

        self._tap_if_present("clr")
        self._tap("digit_8")
        self._tap("op_sub")
        self._tap("digit_3")
        self._tap("eq")
        
        # Try finding result_final first, then result_preview
        try:
            result = self.wait.until(
                lambda driver: driver.find_element(AppiumBy.ID, self._id("result_final"))
            )
        except:
            result = self.wait.until(
                lambda driver: driver.find_element(AppiumBy.ID, self._id("result_preview"))
            )
            
        self.assertEqual("5", result.text)
        print(f"Test Passed: 8 - 3 = {result.text} OK")

    def _tap(self, resource_name: str) -> None:
        element = self.wait.until(
            lambda driver: driver.find_element(AppiumBy.ID, self._id(resource_name))
        )
        element.click()

    def _tap_if_present(self, resource_name: str) -> None:
        try:
            self._tap(resource_name)
        except (NoSuchElementException, TimeoutException):
            pass

    def _id(self, resource_name: str) -> str:
        return f"{calculator_package}:id/{resource_name}"

if __name__ == "__main__":
    import os
    import sys
    if not os.path.exists("results"):
        os.makedirs("results")
    
    class Tee(object):
        def __init__(self, *files):
            self.files = files
        def write(self, obj):
            for f in self.files:
                f.write(obj)
                f.flush()
        def flush(self):
            for f in self.files:
                f.flush()

    with open("results/calculator_8_minus_3_results.txt", "w") as f:
        # Stream to both terminal (stderr) and file
        original_stderr = sys.stderr
        sys.stderr = Tee(sys.stderr, f)
        try:
            unittest.main()
        finally:
            sys.stderr = original_stderr
