*** Settings ***
Library    FlaUILibrary

*** Variables ***
${CALCULATOR_EXE}    C:\\Users\\DudeQ\\Documents\\Programming\\Python\\Robot_framework\\Testowanie_oprogramowania\\Zadanie_2\\Kalkulator\\Calculator.exe
${CALCULATOR_PID}    ${EMPTY}
${CALCULATOR_WINDOW}    Calculator
${DISPLAY_VALUE}    /Window[@Name="Calculator"]/Pane/Text[@AutomationId="158"]
${BUTTON_DIGIT_5}    135
${BUTTON_DIGIT_7}    137
${BUTTON_ADD}    93
${BUTTON_EQUAL}    121    
*** Test Cases ***
Addition In Calculator
    [Teardown]    Close Calculator
    Open Calculator
    Click Button By Automation Id    ${BUTTON_DIGIT_5}
    Click Button By Automation Id    ${BUTTON_ADD}
    Click Button By Automation Id    ${BUTTON_DIGIT_7}
    Click Button By Automation Id    ${BUTTON_EQUAL}
    Result Should Be    12

*** Keywords ***
Open Calculator
    ${pid}=    Launch Application    ${CALCULATOR_EXE}
    Set Test Variable    ${CALCULATOR_PID}    ${pid}
    Wait Until Element Exist    ${CALCULATOR_WINDOW}

Click Button By Automation Id
    [Arguments]    ${automation_id}
    Click    ${CALCULATOR_WINDOW}/Pane/Button[@AutomationId="${automation_id}"]

Close Calculator
    Run Keyword If    '${CALCULATOR_PID}' != '${EMPTY}'    Close Application    ${CALCULATOR_PID}
    Set Test Variable    ${CALCULATOR_PID}    ${EMPTY}

Result Should Be
    [Arguments]    ${expected}
    ${result}=    Get Name From Element    ${DISPLAY_VALUE}
    Should Be Equal As Strings    ${result}    ${expected}
