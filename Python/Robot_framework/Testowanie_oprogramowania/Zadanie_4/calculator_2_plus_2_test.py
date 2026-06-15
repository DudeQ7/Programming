import unittest

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


class TestGoogleCalculator(unittest.TestCase):
    def setUp(self) -> None:
        options = UiAutomator2Options().load_capabilities(capabilities)
        self.driver = webdriver.Remote(appium_server_url, options=options)
        self.driver.update_settings({"ignoreUnimportantViews": False})
        self.wait = WebDriverWait(self.driver, 5)

    def tearDown(self) -> None:
        if self.driver:
            self.driver.quit()

    def test_two_plus_two_equals_four(self) -> None:
        self._tap_if_present("clr")
        self._tap("digit_2")
        self._tap("op_add")
        self._tap("digit_2")
        self._tap("eq")

        result = self.wait.until(
            lambda driver: driver.find_element(AppiumBy.ID, self._id("result_final"))
        )

        self.assertEqual("4", result.text)

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
    unittest.main()
