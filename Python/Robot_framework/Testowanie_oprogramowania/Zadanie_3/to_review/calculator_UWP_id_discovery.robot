*** Settings ***
Library    FlaUILibrary
Library    Process

*** Variables ***
${CALCULATOR_APP}       calc.exe
${CALCULATOR_WINDOW}    /Window[@Name="Kalkulator"]

*** Test Cases ***
Addition In UWP Calculator
    [Teardown]    Close Calculator
    Open Calculator
    Dump Controls

*** Keywords ***
Dump Controls
    @{elements}=    Find All Elements    ${CALCULATOR_WINDOW}//*
    FOR    ${element}    IN    @{elements}
        Log To Console    id=${element.AutomationId} | name=${element.Name} | class=${element.ClassName} | xpath=${element.Xpath}
    END
    Log To Console    ---- Text elements ----
    @{texts}=    Find All Elements    ${CALCULATOR_WINDOW}//Text
    FOR    ${text}    IN    @{texts}
        Log To Console    text-id=${text.AutomationId} | name=${text.Name} | xpath=${text.Xpath}
    END

Open Calculator
    Start Process    ${CALCULATOR_APP}
    Run Keyword And Return Status    Wait Until Element Exist    ${CALCULATOR_WINDOW}

Close Calculator
    IF    '${CALCULATOR_WINDOW}' != '${EMPTY}'
        Run Keyword And Ignore Error    Close Window    ${CALCULATOR_WINDOW}
        Set Test Variable    ${CALCULATOR_WINDOW}    ${EMPTY}
    END
