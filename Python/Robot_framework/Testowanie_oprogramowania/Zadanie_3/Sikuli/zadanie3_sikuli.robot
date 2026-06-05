*** Settings ***
Library    SikuliLibrary    mode=NEW    timeout=10
Library    Process
Library    OperatingSystem

*** Variables ***
${CALCULATOR_APP}       win32calc.exe
${IMAGE_PATH}           ${CURDIR}\\images
${IMAGE_FOLDER}         ${IMAGE_PATH}
${SCREENSHOT_FOLDER}    ${OUTPUT DIR}

# Digit Buttons
${BUTTON_7}             button_7.png
${BUTTON_5}             button_5.png
${BUTTON_4}             button_4.png
${BUTTON_1}             button_1.png

# Operation Buttons
${BUTTON_ADD}           button_plus.png
${BUTTON_MINUS}         button_minus.png
${BUTTON_MULT}          button_multiplication.png
${BUTTON_DIV}           button_division.png
${BUTTON_EQUALS}        button_equals.png

# Expected Results
${RESULT_11}            result_11.png
${RESULT_12}            result_12.png

${CALCULATOR_STARTED}   ${FALSE}
${SIKULI_STARTED}       ${FALSE}

*** Test Cases ***
Perform Four Mathematical Operations
    [Setup]       Configure Sikuli
    [Teardown]    Stop Sikuli Server
    
    # Operation 1: 7 + 4 = 11
    Execute Addition    ${BUTTON_7}    ${BUTTON_4}    ${RESULT_11}
    
    # Operation 2: 7 + 5 = 12
    Execute Addition    ${BUTTON_7}    ${BUTTON_5}    ${RESULT_12}
    
    # Operation 3: 4 + 7 = 11
    Execute Addition    ${BUTTON_4}    ${BUTTON_7}    ${RESULT_11}
    
    # Operation 4: 5 + 7 = 12
    Execute Addition    ${BUTTON_5}    ${BUTTON_7}    ${RESULT_12}

*** Keywords ***
Configure Sikuli
    Directory Should Exist    ${IMAGE_FOLDER}
    Start Sikuli Process
    Set Test Variable    ${SIKULI_STARTED}    ${TRUE}
    Add Image Path    ${IMAGE_FOLDER}
    Set Capture Folder    ${SCREENSHOT_FOLDER}
    Set Min Similarity    0.4
    Set Timeout    30

Open Calculator
    # Preemptive cleanup
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    CalculatorApp.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T

    Start Process    ${CALCULATOR_APP}
    Set Test Variable    ${CALCULATOR_STARTED}    ${TRUE}
    Sleep    8s
    # Wait for the first button to ensure app is ready
    Wait Until Screen Contain    ${BUTTON_7}    30

Execute Addition
    [Arguments]    ${val1}    ${val2}    ${expected_result}
    Open Calculator
    Click Calculator Image    ${val1}
    Click Calculator Image    ${BUTTON_ADD}
    Click Calculator Image    ${val2}
    Click Calculator Image    ${BUTTON_EQUALS}
    Result Image Should Be Visible    ${expected_result}
    Log    Operation Successful. Waiting 15 seconds before next step...
    Sleep    15s
    Close Calculator

Click Calculator Image
    [Arguments]    ${image_name}
    Wait Until Screen Contain    ${image_name}    30
    Click    ${image_name}
    Sleep    1s

Result Image Should Be Visible
    [Arguments]    ${image_name}
    Sleep    5s
    # Low similarity for result area
    Set Min Similarity    0.3
    Wait Until Screen Contain    ${image_name}    30
    # Reset similarity for buttons
    Set Min Similarity    0.4

Close Calculator
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    CalculatorApp.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    Set Test Variable    ${CALCULATOR_STARTED}    ${FALSE}

Stop Sikuli Server
    IF    ${SIKULI_STARTED}
        Run Keyword And Ignore Error    Stop Remote Server
        Set Test Variable    ${SIKULI_STARTED}    ${FALSE}
    END
