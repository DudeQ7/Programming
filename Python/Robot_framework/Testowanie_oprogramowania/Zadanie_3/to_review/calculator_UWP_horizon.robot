*** Settings ***
Library    ImageHorizonLibrary
Library    Process
Library    OperatingSystem

*** Variables ***
${CALCULATOR_APP}       calc.exe
${IMAGE_FOLDER}         ${CURDIR}\\images\\calculator_uwp
${SCREENSHOT_FOLDER}    ${OUTPUT DIR}
${BUTTON_DIGIT_7}       button_digit_7
${BUTTON_DIGIT_5}       button_digit_5
${BUTTON_ADD}           button_add
${BUTTON_EQUALS}        button_equals
${RESULT_12}            result_12
${CALCULATOR_STARTED}   ${FALSE}

*** Test Cases ***
Addition In UWP Calculator With Image Recognition
    [Teardown]    Close Calculator
    Configure Image Recognition
    Open Calculator
    Click Calculator Image    ${BUTTON_DIGIT_7}
    Click Calculator Image    ${BUTTON_ADD}
    Click Calculator Image    ${BUTTON_DIGIT_5}
    Click Calculator Image    ${BUTTON_EQUALS}
    Result Image Should Be Visible    ${RESULT_12}

*** Keywords ***
Configure Image Recognition
    Directory Should Exist    ${IMAGE_FOLDER}
    Set Reference Folder    ${IMAGE_FOLDER}
    Set Screenshot Folder    ${SCREENSHOT_FOLDER}
    Set Confidence    0.9

Open Calculator
    Start Process    ${CALCULATOR_APP}
    Set Test Variable    ${CALCULATOR_STARTED}    ${TRUE}
    Wait For Calculator Image    ${BUTTON_DIGIT_7}

Click Calculator Image
    [Arguments]    ${image_name}
    Wait For Calculator Image    ${image_name}
    Click Image    ${image_name}

Result Image Should Be Visible
    [Arguments]    ${image_name}
    Wait For Calculator Image    ${image_name}

Wait For Calculator Image
    [Arguments]    ${image_name}
    Wait Until Keyword Succeeds    10x    1s    Wait For    ${image_name}    timeout=1

Close Calculator
    IF    ${CALCULATOR_STARTED}
        Run Keyword And Ignore Error    Run Process    taskkill    /IM    CalculatorApp.exe    /F
        Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F
        Set Test Variable    ${CALCULATOR_STARTED}    ${FALSE}
    END
