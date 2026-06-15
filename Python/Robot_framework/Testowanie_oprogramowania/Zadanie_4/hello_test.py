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
    locale='US'
)

appium_server_url = 'http://localhost:4723'

class TestAppium(unittest.TestCase):
    def setUp(self) -> None:
        options = UiAutomator2Options().load_capabilities(capabilities)
        self.driver = webdriver.Remote(appium_server_url, options=options)

    def tearDown(self) -> None:
        if self.driver:
            self.driver.quit()

    def test_find_battery(self) -> None:
        # el = self.driver.find_element(by=AppiumBy.XPATH, value='//*[@text="Battery"]')
        el = self.driver.find_element(by=AppiumBy.XPATH, value='//*[@text="Sounds and vibration"]')
        el.click()
        el = self.driver.find_element(by=AppiumBy.XPATH, value='//*[@text="Call vibration"]')
        el.click()

        sounds = ['Heartbeat', 'Ticktock', 'Waltz', 'Siren', 'Basic call']
        for sound in sounds:
            el = self.driver.find_element(by=AppiumBy.XPATH, value=f'//*[@text="{sound}"]')
            el.click()
            time.sleep(3)

if __name__ == '__main__':
    unittest.main()
