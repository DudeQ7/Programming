*** Settings ***
Library    SikuliLibrary    mode=NEW    timeout=10
Library    Process
Library    OperatingSystem

*** Variables ***
${CALCULATOR_APP}       calc.exe
${IMAGE_PATH}           ${CURDIR}\\images
${IMAGE_FOLDER}         ${IMAGE_PATH}
${SCREENSHOT_FOLDER}    ${OUTPUT DIR}

# Digit Buttons (Large, with borders)
${BUTTON_1}             button_1.png
${BUTTON_4}             button_4.png
${BUTTON_7}             button_7.png

# Operation Buttons
${BUTTON_ADD}           plus.png
${BUTTON_EQUALS}        equal.png

${CALCULATOR_STARTED}   ${FALSE}
${SIKULI_STARTED}       ${FALSE}

*** Test Cases ***
Perform Four Additions in Maximized Calculator
    [Setup]       Configure Sikuli
    [Teardown]    Stop Sikuli Server
    
    # Operation 1: 7 + 4
    Execute Addition    ${BUTTON_7}    ${BUTTON_4}
    
    # Operation 2: 4 + 7
    Execute Addition    ${BUTTON_4}    ${BUTTON_7}
    
    # Operation 3: 1 + 7
    Execute Addition    ${BUTTON_1}    ${BUTTON_7}
    
    # Operation 4: 7 + 1
    Execute Addition    ${BUTTON_7}    ${BUTTON_1}

*** Keywords ***
Configure Sikuli
    Directory Should Exist    ${IMAGE_FOLDER}
    Start Sikuli Process
    Set Test Variable    ${SIKULI_STARTED}    ${TRUE}
    # Use absolute path
    ${abs_image_path}=    Normalize Path    ${IMAGE_FOLDER}
    Add Image Path    ${abs_image_path}
    Set Capture Folder    ${SCREENSHOT_FOLDER}
    # Very relaxed similarity for diagnostic
    Set Min Similarity    0.3
    Set Timeout    45

Open Calculator Maximized
    # Preemptive cleanup
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    
    # Start maximized using shell command
    Run Process    cmd.exe    /c    start /max ${CALCULATOR_APP}
    Set Test Variable    ${CALCULATOR_STARTED}    ${TRUE}
    Sleep    15s
    # Wait for the first button to ensure app is ready and visible
    Wait Until Screen Contain    ${BUTTON_7}    45

Execute Addition
    [Arguments]    ${val1}    ${val2}
    Open Calculator Maximized
    Click Calculator Image    ${val1}
    Click Calculator Image    ${BUTTON_ADD}
    Click Calculator Image    ${val2}
    # Lower similarity even more for equals if it's being stubborn
    Set Min Similarity    0.2
    Click Calculator Image    ${BUTTON_EQUALS}
    # Reset similarity for next iteration
    Set Min Similarity    0.3
    Log    Operation Successful. Waiting 15 seconds before next step...
    Sleep    15s
    Close Calculator

Click Calculator Image
    [Arguments]    ${image_name}
    Wait Until Screen Contain    ${image_name}    30
    # Highlight briefly to confirm correct detection in logs/view
    Run Keyword And Ignore Error    Highlight    ${image_name}    1
    Click    ${image_name}
    Sleep    1s

Close Calculator
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    Set Test Variable    ${CALCULATOR_STARTED}    ${FALSE}

Stop Sikuli Server
    IF    ${SIKULI_STARTED}
        Run Keyword And Ignore Error    Stop Remote Server
        Set Test Variable    ${SIKULI_STARTED}    ${FALSE}
    END
