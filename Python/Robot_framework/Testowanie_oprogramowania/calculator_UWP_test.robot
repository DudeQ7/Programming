*** Settings ***
Library    FlaUILibrary
Library    Process

*** Variables ***
${CALCULATOR_APP}    calc.exe
${CALCULATOR_WINDOW}    /Window[@Name="Kalkulator"]

*** Test Cases ***
Addition In UWP Calculator
    [Teardown]    Close Calculator
    Open Calculator
    Click Calculator Button    num7Button
    Click Calculator Button    plusButton
    Click Calculator Button    num5Button
    Click Calculator Button    equalButton
    Result Should Be    12

*** Keywords ***
Open Calculator
    Start Process    ${CALCULATOR_APP}
    Run Keyword And Return Status    Wait Until Element Exist    ${CALCULATOR_WINDOW}

Click Calculator Button
    [Arguments]    ${automation_id}
    Click    ${CALCULATOR_WINDOW}//Button[@AutomationId="${automation_id}"]

Close Calculator
    IF    '${CALCULATOR_WINDOW}' != '${EMPTY}'
        Run Keyword And Ignore Error    Close Window    ${CALCULATOR_WINDOW}
        Set Test Variable    ${CALCULATOR_WINDOW}    ${EMPTY}
    END

Result Should Be
    [Arguments]    ${expected}
    ${result}=    Get Name From Element    ${CALCULATOR_WINDOW}//Text[@AutomationId="CalculatorResults"]
    Should Contain    ${result}    ${expected}
