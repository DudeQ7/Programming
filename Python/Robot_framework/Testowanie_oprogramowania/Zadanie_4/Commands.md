# pip install robotframework-appiumlibrary selenium Appium-Python-Client\
Linux:
sudo pacman -S nodejs npm android-tools android-udev 
yay -S  android-sdk android-sdk-platform-tools android-sdk-build-tools

sudo npm install -g appium 
appium driver install uiautomator2 

export ANDROID_HOME=/opt/android-sdk
appium -by serwer wystartowal 

set -Ux ANDROID_HOME /opt/android-sdk
fish_add_path /opt/android-sdk/platform-tools
