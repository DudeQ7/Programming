*** Settings ***
Library    FlaUILibrary

*** Variables ***
${CALCULATOR_EXE}       ${CURDIR}/win32calc.exe
${WINDOW_NAME}          Calculator
${CALCULATOR_PID}       ${EMPTY}
# Use a flexible locator for English or Polish OS
${CALCULATOR_WINDOW}    /Window[contains(@Name, "alculator") or contains(@Name, "alkulator")]
# Old calc might not have a Pane, using deep search //
${DISPLAY_VALUE}        ${CALCULATOR_WINDOW}//Text[@AutomationId="158"]
${BUTTON_DIGIT_3}       133
${BUTTON_DIGIT_5}       135
${BUTTON_DIGIT_7}       137
${BUTTON_DIGIT_9}       139
${BUTTON_SUBTRACT}      94
${BUTTON_ADD}           93
${BUTTON_MULTIPLY}      92
${BUTTON_DIVIDE}        91
${BUTTON_EQUAL}         121    
${BUTTON_NEGATE}        80
${BUTTON_CLEAR}         81
*** Test Cases ***
Addition In Calculator
    [Teardown]    Close Calculator
    Open Calculator
    Click Button By Automation Id    ${BUTTON_CLEAR}
    Click Button By Automation Id    ${BUTTON_DIGIT_5}
    Click Button By Automation Id    ${BUTTON_ADD}
    Click Button By Automation Id    ${BUTTON_DIGIT_7}
    Click Button By Automation Id    ${BUTTON_EQUAL}
    Result Should Be    12

Subtraction In Calculator
    [Teardown]    Close Calculator
    Open Calculator
    Click Button By Automation Id    ${BUTTON_CLEAR}
    Click Button By Automation Id    ${BUTTON_DIGIT_7}
    Click Button By Automation Id    ${BUTTON_SUBTRACT}
    Click Button By Automation Id    ${BUTTON_DIGIT_5}
    Click Button By Automation Id    ${BUTTON_EQUAL}
    Result Should Be    2

Multiplication In Calculator
    [Teardown]    Close Calculator
    Open Calculator
    Click Button By Automation Id    ${BUTTON_CLEAR}
    Click Button By Automation Id    ${BUTTON_DIGIT_7}
    Click Button By Automation Id    ${BUTTON_MULTIPLY}
    Click Button By Automation Id    ${BUTTON_DIGIT_5}
    Click Button By Automation Id    ${BUTTON_EQUAL}
    Result Should Be    35

Division In Calculator
    [Teardown]     Close Calculator
    Open Calculator 
    Click Button By Automation Id    ${BUTTON_CLEAR}
    Click Button By Automation Id    ${BUTTON_DIGIT_9}
    Click Button By Automation Id    ${BUTTON_DIVIDE}
    Click Button By Automation Id    ${BUTTON_DIGIT_3}
    Click Button By Automation Id    ${BUTTON_EQUAL}
    Result Should Be    3

Negation In Calculator
    [Teardown]    Close Calculator 
    Open Calculator
    Click Button By Automation Id    ${BUTTON_CLEAR}
    Click Button By Automation Id    ${BUTTON_DIGIT_5}
    Click Button By Automation Id    ${BUTTON_NEGATE}
    Click Button By Automation Id    ${BUTTON_ADD}
    Click Button By Automation Id    ${BUTTON_DIGIT_7}
    Click Button By Automation Id    ${BUTTON_EQUAL}
    Result Should Be    2

*** Keywords ***
Open Calculator
    ${pid}=    Launch Application    ${CALCULATOR_EXE}
    Set Test Variable    ${CALCULATOR_PID}    ${pid}
    Wait Until Element Exist    ${CALCULATOR_WINDOW}

Click Button By Automation Id
    [Arguments]    ${automation_id}
    Click    ${CALCULATOR_WINDOW}//Button[@AutomationId="${automation_id}"]

Close Calculator
    Run Keyword If    '${CALCULATOR_PID}' != '${EMPTY}'    Close Application    ${CALCULATOR_PID}
    Set Test Variable    ${CALCULATOR_PID}    ${EMPTY}

Result Should Be
    [Arguments]    ${expected}
    ${result}=    Get Name From Element    ${DISPLAY_VALUE}
    Should Be Equal As Strings    ${result}    ${expected}
