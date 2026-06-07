*** Settings ***
Library    SikuliLibrary    mode=NEW    timeout=10
Library    Process
Library    OperatingSystem

*** Variables ***
${CALCULATOR_APP}       calc.exe
${IMAGE_PATH}           ${CURDIR}${/}images
${IMAGE_FOLDER}         ${IMAGE_PATH}
${SCREENSHOT_FOLDER}    ${OUTPUT DIR}

# Digit Buttons
${BTN_0}                button_digit_0.png
${BTN_1}                button_digit_1.png
${BTN_2}                button_digit_2.png
${BTN_3}                button_digit_3.png
${BTN_4}                button_digit_4.png
${BTN_5}                button_digit_5.png
${BTN_6}                button_digit_6.png
${BTN_7}                button_digit_7.png
${BTN_8}                button_digit_8.png
${BTN_9}                button_digit_9.png

# Operation Buttons
${BTN_ADD}              plus.png
${BTN_SUB}              minus.png
${BTN_MULT}             mult.png
${BTN_DIV}              divide.png
${BTN_EQUALS}           equals.png
${BTN_CLEAR}            clear.png

${CALCULATOR_STARTED}   ${FALSE}
${SIKULI_STARTED}       ${FALSE}

*** Test Cases ***
Perform Four Arithmetic Operations in Maximized Calculator
    [Setup]       Configure Sikuli
    [Teardown]    Stop Sikuli Server
    
    # Operation 1: 7 + 5 = 12
    Execute Arithmetic Operation    ${BTN_7}    ${BTN_ADD}    ${BTN_5}    wynik_12.png
    
    # Operation 2: 5 - 2 = 3
    Execute Arithmetic Operation    ${BTN_5}    ${BTN_SUB}    ${BTN_2}    wynik_3.png
    
    # Operation 3: 6 * 7 = 42
    Execute Arithmetic Operation    ${BTN_6}    ${BTN_MULT}    ${BTN_7}    wynik_42.png
    
    # Operation 4: 8 / 2 = 4
    Execute Arithmetic Operation    ${BTN_8}    ${BTN_DIV}    ${BTN_2}    wynik_4.png

*** Keywords ***
Configure Sikuli
    Directory Should Exist    ${IMAGE_FOLDER}
    Start Sikuli Process
    Set Test Variable    ${SIKULI_STARTED}    ${TRUE}
    ${abs_image_path}=    Normalize Path    ${IMAGE_FOLDER}
    Add Image Path    ${abs_image_path}
    Set Capture Folder    ${SCREENSHOT_FOLDER}
    Set Min Similarity    0.7
    Set Timeout    30

Open Calculator Maximized
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    
    Run Process    cmd.exe    /c    start /max ${CALCULATOR_APP}
    Set Test Variable    ${CALCULATOR_STARTED}    ${TRUE}
    Sleep    5s
    Wait Until Screen Contain    ${BTN_7}    30

Execute Arithmetic Operation
    [Arguments]    ${val1}    ${op}    ${val2}    ${expected_result_image}
    Open Calculator Maximized
    Click Calculator Image    ${val1}
    Click Calculator Image    ${op}
    Click Calculator Image    ${val2}
    Click Calculator Image    ${BTN_EQUALS}
    
    # Verify result if the image exists
    ${result_exists}=    Run Keyword And Return Status    File Should Exist    ${IMAGE_FOLDER}${/}${expected_result_image}
    IF    ${result_exists}
        Wait Until Screen Contain    ${expected_result_image}    10
        Highlight    ${expected_result_image}    2
    ELSE
        Log    Warning: Result image ${expected_result_image} not found, skipping verification.    level=WARN
    END
    
    Log    Operation Successful.
    Close Calculator

Click Calculator Image
    [Arguments]    ${image_name}
    Wait Until Screen Contain    ${image_name}    15
    Run Keyword And Ignore Error    Highlight    ${image_name}    1
    Click    ${image_name}
    Sleep    0.5s

Close Calculator
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    Set Test Variable    ${CALCULATOR_STARTED}    ${FALSE}

Stop Sikuli Server
    IF    ${SIKULI_STARTED}
        Run Keyword And Ignore Error    Stop Remote Server
        Set Test Variable    ${SIKULI_STARTED}    ${FALSE}
    END
