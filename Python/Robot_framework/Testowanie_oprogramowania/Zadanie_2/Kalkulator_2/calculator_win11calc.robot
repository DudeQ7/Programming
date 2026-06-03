*** Settings ***
Library    FlaUILibrary

*** Variables ***
${CALCULATOR_EXE}    ${CURDIR}/calc.exe
${CALCULATOR_PID}    ${EMPTY}
${CALCULATOR_WINDOW}  /Window[@Name="Calculator"]
${DISPLAY_VALUE}    ${CALCULATOR_WINDOW}//Text[@AutomationId="CalculatorResults"]
${BUTTON_DIGIT_5}    num5Button
${BUTTON_DIGIT_7}    num7Button
${BUTTON_DIGIT_9}    num9Button
${BUTTON_DIGIT_3}    num3Button
${BUTTTON_ADD}       plusButton
${BUTTON_SUBTRACT}   minusButton
${BUTTON_MULTIPLY}   multiplyButton
${BUTTON_NEGATE}     negateButton
${BUTTON_DIVIDE}     divideButton
${BUTTON_CLEAR}      clearButton
${BUTTON_EQUAL}      equalButton

*** Test Cases ***
Addition In Calculator
    [Teardown]    Close Calculator    
    Open Calculator
    Click Button By Automation Id    ${BUTTON_CLEAR}
    Click Button By Automation Id    ${BUTTON_DIGIT_5}
    Click Button By Automation Id    ${BUTTTON_ADD}
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
    [Teardown]    Close Calculator
    Open Calculator
    Click Button By Automation Id    ${BUTTON_CLEAR}
    Click Button By Automation Id    ${BUTTON_DIGIT_9}
    Click Button By Automation Id    ${BUTTON_DIVIDE}
    Click Button By Automation Id    ${BUTTON_DIGIT_3}
    Click Button By Automation Id    ${BUTTON_EQUAL}
    Result Should Be   3
Negation In Calculator 
    [Teardown]    Close Calculator
    Open Calculator
    Click Button By Automation Id    ${BUTTON_CLEAR}
    Click Button By Automation Id    ${BUTTON_DIGIT_5}
    Click Button By Automation Id    ${BUTTON_NEGATE}
    Click Button By Automation Id    ${BUTTTON_ADD}
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
    ${exists}=    Run Keyword And Return Status    Element Should Exist    ${CALCULATOR_WINDOW}  
    Run Keyword If    ${exists}    Close Window    ${CALCULATOR_WINDOW}
    Set Test Variable    ${CALCULATOR_PID}    ${EMPTY}
    Run Keyword If    '${CALCULATOR_PID}' != '${EMPTY}'    Close Application    ${CALCULATOR_PID}
    Set Test Variable    ${CALCULATOR_PID}    ${EMPTY}

Result Should Be 
    [Arguments]    ${expected}
    ${result}=    Get Name From Element    ${DISPLAY_VALUE}
    Should Contain    ${result}    ${expected}