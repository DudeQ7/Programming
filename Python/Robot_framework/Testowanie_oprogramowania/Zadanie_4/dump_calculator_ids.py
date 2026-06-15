from xml.etree import ElementTree
from appium import webdriver
from appium.options.android import UiAutomator2Options
appium_server_url = "http://localhost:4723"
capabilities = {
    "platformName": "Android",
    "automationName": "uiautomator2",
    "deviceName": "Android",
    "appPackage": "com.google.android.calculator",
    "appActivity": "com.android.calculator2.Calculator",
    "noReset": True,
    "newCommandTimeout": 60,
}
def main() -> None:
    options = UiAutomator2Options().load_capabilities(capabilities)
    driver = webdriver.Remote(appium_server_url, options=options)
    try:
        driver.update_settings({"ignoreUnimportantViews": False})
        print(f"Package: {driver.current_package}")
        print(f"Activity: {driver.current_activity}")
        print()
        print("Calculator element ids:")
        root = ElementTree.fromstring(driver.page_source)
        found_ids = set()
        for element in root.iter():
            resource_id = element.attrib.get("resource-id", "").strip()
            if not resource_id or resource_id in found_ids:
                continue
            found_ids.add(resource_id)
            class_name = element.attrib.get("class", element.tag)
            text = element.attrib.get("text", "")
            description = element.attrib.get("content-desc", "")
            bounds = element.attrib.get("bounds", "")
            print(
                f"{resource_id} | class={class_name} | "
                f"text={text!r} | content-desc={description!r} | bounds={bounds}"
            )

        print()
        print(f"Total unique ids: {len(found_ids)}")
    finally:
        driver.quit()
if __name__ == "__main__":
    main()
