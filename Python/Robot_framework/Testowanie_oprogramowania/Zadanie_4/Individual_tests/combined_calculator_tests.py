import unittest
import time
import os
import sys
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
class TestGoogleCalculatorCombined(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        options = UiAutomator2Options().load_capabilities(capabilities)
        cls.driver = webdriver.Remote(appium_server_url, options=options)
        cls.driver.update_settings({"ignoreUnimportantViews": False})
        cls.wait = WebDriverWait(cls.driver, 10)
    @classmethod
    def tearDownClass(cls) -> None:
        if cls.driver:
            cls.driver.quit()
    def setUp(self) -> None:
        self.driver.terminate_app(calculator_package)
        self.driver.activate_app(calculator_package)
        time.sleep(2)
        self._tap_if_present("clr")
    def test_1_two_plus_two_equals_four(self) -> None:
        print("\nRunning Test: 2 + 2 = 4")
        self._tap("digit_2")
        self._tap("op_add")
        self._tap("digit_2")
        self._tap("eq")
        result = self._get_result()
        self.assertEqual("4", result)
        print(f"Result: {result} - PASSED")
    def test_2_seven_times_seven_equals_forty_nine(self) -> None:
        print("\nRunning Test: 7 * 7 = 49")
        self._tap("digit_7")
        self._tap("op_mul")
        self._tap("digit_7")
        self._tap("eq")
        result = self._get_result()
        self.assertEqual("49", result)
        print(f"Result: {result} - PASSED")
    def test_3_eight_minus_three_equals_five(self) -> None:
        print("\nRunning Test: 8 - 3 = 5")
        self._tap("digit_8")
        self._tap("op_sub")
        self._tap("digit_3")
        self._tap("eq")
        result = self._get_result()
        self.assertEqual("5", result)
        print(f"Result: {result} - PASSED")
    def test_4_nine_divided_by_three_equals_three(self) -> None:
        print("\nRunning Test: 9 / 3 = 3")
        self._tap("digit_9")
        self._tap("op_div")
        self._tap("digit_3")
        self._tap("eq")
        result = self._get_result()
        self.assertEqual("3", result)
        print(f"Result: {result} - PASSED")
    def test_5_negation_minus_five_plus_three_equals_negative_two(self) -> None:
        print("\nRunning Test: -5 + 3 = -2")
        self._tap("op_sub")
        self._tap("digit_5")
        self._tap("op_add")
        self._tap("digit_3")
        self._tap("eq")
        result = self._get_result()
        self.assertEqual("−2", result)
        print(f"Result: {result} - PASSED")
    def _get_result(self) -> str:
        try:
            element = self.wait.until(
                lambda driver: driver.find_element(AppiumBy.ID, self._id("result_final"))
            )
        except:
            element = self.wait.until(
                lambda driver: driver.find_element(AppiumBy.ID, self._id("result_preview"))
            )
        return element.text
    def _tap(self, resource_name: str) -> None:
        element = self.wait.until(
            lambda driver: driver.find_element(AppiumBy.ID, self._id(resource_name))
        )
        element.click()
    def _tap_if_present(self, resource_name: str) -> None:
        try:
            element = self.driver.find_element(AppiumBy.ID, self._id(resource_name))
            element.click()
        except (NoSuchElementException, TimeoutException):
            pass
    def _id(self, resource_name: str) -> str:
        return f"{calculator_package}:id/{resource_name}"
if __name__ == "__main__":
    base_dir = os.path.dirname(os.path.abspath(__file__))
    results_dir = os.path.join(base_dir, "results")
    os.makedirs(results_dir, exist_ok=True)
    timestamp = time.strftime("%Y%m%d_%H%M%S")
    results_file = os.path.join(results_dir, f"combined_test_results_{timestamp}.txt")
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

    with open(results_file, "w") as f:
        original_stdout = sys.stdout
        original_stderr = sys.stderr
        sys.stdout = Tee(sys.stdout, f)
        sys.stderr = Tee(sys.stderr, f)
        
        print("="*50)
        print("TESTS:")
        print("="*50)
        
        try:
            suite = unittest.TestLoader().loadTestsFromTestCase(TestGoogleCalculatorCombined)
            runner = unittest.TextTestRunner(verbosity=2)
            result = runner.run(suite)
            
            print("\n" + "="*50)
            print("SUMMARY")
            print("="*50)
            print(f"Total Tests Run: {result.testsRun}")
            print(f"Passed: {result.testsRun - len(result.failures) - len(result.errors)}")
            print(f"Failed: {len(result.failures)}")
            print(f"Errors: {len(result.errors)}")
            print("="*50)
            if not result.wasSuccessful():
                sys.exit(1)
        finally:
            sys.stdout = original_stdout
            sys.stderr = original_stderr
