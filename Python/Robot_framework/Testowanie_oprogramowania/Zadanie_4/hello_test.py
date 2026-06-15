import unittest
import time
from appium import webdriver
from appium.options.android import UiAutomator2Options
from appium.webdriver.common.appiumby import AppiumBy

capabilities = dict(
    platformName='Android',
    automationName='uiautomator2',
    deviceName='Android',
    appPackage='com.android.settings',
    appActivity='.Settings',
    language='en',
    locale='US',
    noReset=True
)

appium_server_url = 'http://localhost:4723'

class TestAppium(unittest.TestCase):
    def setUp(self) -> None:
        options = UiAutomator2Options().load_capabilities(capabilities)
        self.driver = webdriver.Remote(appium_server_url, options=options)

    def tearDown(self) -> None:
        if self.driver:
            self.driver.quit()

    def test_find_sound_settings(self) -> None:
        # Restart settings to ensure we are on the main screen
        self.driver.terminate_app("com.android.settings")
        self.driver.activate_app("com.android.settings")
        time.sleep(2)

        # Scroll to and click "Sound & vibration"
        scroll_view = 'new UiScrollable(new UiSelector().scrollable(true)).scrollIntoView(new UiSelector().textContains("Sound & vibration"))'
        el = self.driver.find_element(by=AppiumBy.ANDROID_UIAUTOMATOR, value=scroll_view)
        el.click()
        print("Successfully clicked Sound & vibration")
        time.sleep(2)

if __name__ == '__main__':
    import os
    if not os.path.exists("results"):
        os.makedirs("results")
    
    with open("results/hello_test_results.txt", "w") as f:
        runner = unittest.TextTestRunner(stream=f, verbosity=2)
        unittest.main(testRunner=runner)
