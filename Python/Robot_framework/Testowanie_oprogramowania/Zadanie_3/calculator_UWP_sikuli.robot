*** Settings ***
Library    SikuliLibrary    mode=NEW    timeout=10
Library    Process
Library    OperatingSystem

*** Variables ***
${CALCULATOR_APP}       calc.exe
${IMAGE_FOLDER}         ${CURDIR}\\images\\calculator_uwp
${SCREENSHOT_FOLDER}    ${OUTPUT DIR}
${BUTTON_DIGIT_7}       button_digit_7.png
${BUTTON_DIGIT_5}       button_digit_5.png
${BUTTON_ADD}           button_add.png
${BUTTON_EQUALS}        button_equals.png
${RESULT_12}            result_12.png
${CALCULATOR_STARTED}   ${FALSE}
${SIKULI_STARTED}       ${FALSE}

*** Test Cases ***
Addition In UWP Calculator With Sikuli Image Recognition
    [Teardown]    Close Calculator And Sikuli
    Configure Sikuli
    Open Calculator
    Click Calculator Image    ${BUTTON_DIGIT_7}
    Click Calculator Image    ${BUTTON_ADD}
    Click Calculator Image    ${BUTTON_DIGIT_5}
    Click Calculator Image    ${BUTTON_EQUALS}
    Result Image Should Be Visible    ${RESULT_12}

*** Keywords ***
Configure Sikuli
    Directory Should Exist    ${IMAGE_FOLDER}
    Start Sikuli Process
    Set Test Variable    ${SIKULI_STARTED}    ${TRUE}
    Add Image Path    ${IMAGE_FOLDER}
    Set Capture Folder    ${SCREENSHOT_FOLDER}
    Set Min Similarity    0.9
    Set Timeout    10

Open Calculator
    Start Process    ${CALCULATOR_APP}
    Set Test Variable    ${CALCULATOR_STARTED}    ${TRUE}
    Wait For Calculator Image    ${BUTTON_DIGIT_7}

Click Calculator Image
    [Arguments]    ${image_name}
    Wait For Calculator Image    ${image_name}
    Click    ${image_name}

Result Image Should Be Visible
    [Arguments]    ${image_name}
    Wait For Calculator Image    ${image_name}

Wait For Calculator Image
    [Arguments]    ${image_name}
    Wait Until Keyword Succeeds    10x    1s    Wait Until Screen Contain    ${image_name}    1

Close Calculator And Sikuli
    IF    ${CALCULATOR_STARTED}
        Run Keyword And Ignore Error    Run Process    taskkill    /IM    CalculatorApp.exe    /F
        Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F
        Set Test Variable    ${CALCULATOR_STARTED}    ${FALSE}
    END
    IF    ${SIKULI_STARTED}
        Run Keyword And Ignore Error    Stop Remote Server
        Set Test Variable    ${SIKULI_STARTED}    ${FALSE}
    END
