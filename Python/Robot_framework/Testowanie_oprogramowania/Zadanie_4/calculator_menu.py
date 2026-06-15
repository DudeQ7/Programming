import time
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
    "newCommandTimeout": 300,
}

class CalculatorController:
    def __init__(self):
        options = UiAutomator2Options().load_capabilities(capabilities)
        print("Connecting to Appium server...")
        self.driver = webdriver.Remote(appium_server_url, options=options)
        self.driver.update_settings({"ignoreUnimportantViews": False})
        self.wait = WebDriverWait(self.driver, 5)

    def close(self):
        if self.driver:
            self.driver.quit()

    def _id(self, resource_name: str) -> str:
        return f"{calculator_package}:id/{resource_name}"

    def _tap(self, resource_name: str):
        element = self.wait.until(
            lambda driver: driver.find_element(AppiumBy.ID, self._id(resource_name))
        )
        element.click()

    def _tap_if_present(self, resource_name: str):
        try:
            self._tap(resource_name)
        except (NoSuchElementException, TimeoutException):
            pass

    def _get_result(self) -> str:
        try:
            result = self.wait.until(
                lambda driver: driver.find_element(AppiumBy.ID, self._id("result_final"))
            )
        except:
            result = self.wait.until(
                lambda driver: driver.find_element(AppiumBy.ID, self._id("result_preview"))
            )
        return result.text

    def prepare_app(self):
        self.driver.terminate_app(calculator_package)
        self.driver.activate_app(calculator_package)
        time.sleep(1)
        self._tap_if_present("clr")

    def op_2_plus_2(self):
        self.prepare_app()
        self._tap("digit_2")
        self._tap("op_add")
        self._tap("digit_2")
        self._tap("eq")
        print(f"Result (2 + 2): {self._get_result()}")

    def op_7_times_7(self):
        self.prepare_app()
        self._tap("digit_7")
        self._tap("op_mul")
        self._tap("digit_7")
        self._tap("eq")
        print(f"Result (7 * 7): {self._get_result()}")

    def op_8_minus_3(self):
        self.prepare_app()
        self._tap("digit_8")
        self._tap("op_sub")
        self._tap("digit_3")
        self._tap("eq")
        print(f"Result (8 - 3): {self._get_result()}")

    def op_9_per_3(self):
        self.prepare_app()
        self._tap("digit_9")
        self._tap("op_div")
        self._tap("digit_3")
        self._tap("eq")
        print(f"Result (9 / 3): {self._get_result()}")

    def op_negation_5_plus_3(self):
        self.prepare_app()
        self._tap("op_sub") # Using op_sub as negation as discovered
        self._tap("digit_5")
        self._tap("op_add")
        self._tap("digit_3")
        self._tap("eq")
        print(f"Result (-5 + 3): {self._get_result()}")

def main():
    try:
        calc = CalculatorController()
    except Exception as e:
        print(f"Failed to connect to Appium: {e}")
        return

    while True:
        print("\n--- Android Calculator Menu ---")
        print("1. 2 + 2")
        print("2. 7 * 7")
        print("3. 8 - 3")
        print("4. 9 / 3")
        print("5. -5 + 3")
        print("q. Exit")
        
        choice = input("Select an option: ").strip().lower()

        match choice:
            case '1':
                calc.op_2_plus_2()
            case '2':
                calc.op_7_times_7()
            case '3':
                calc.op_8_minus_3()
            case '4':
                calc.op_9_per_3()
            case '5':
                calc.op_negation_5_plus_3()
            case 'q' | 'quit' | 'exit':
                print("Exiting...")
                break
            case _:
                print("Invalid option. Please try again.")

    calc.close()

if __name__ == "__main__":
    main()
