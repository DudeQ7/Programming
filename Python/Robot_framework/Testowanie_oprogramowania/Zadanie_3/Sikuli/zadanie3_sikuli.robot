*** Settings ***
Library           SikuliLibrary
Library           Process

*** Variables ***
${IMAGE_PATH}     ${CURDIR}/images/
${APP}            calc.exe

*** Test Cases ***
Addition In Calculator
    [Setup]       Add Image Path    ${IMAGE_PATH}
    [Teardown]    Reset Environment
    Start Process    ${APP}
    Wait Until Screen Contain    calc_header.png    10
    # Klikamy nagłówek i czekamy chwilę na fokus
    Click    calc_header.png
    Sleep    1s
    Click    button_5.png
    Click    button_plus.png
    Click    button_3.png
    Click    equal.png
    Screen Should Contain    result_8.png
*** Test Cases ***
Subtraction In Calculator
    [Setup]       Add Image Path    ${IMAGE_PATH}
    [Teardown]    Reset Environment
    Start Process    ${APP}
    Wait Until Screen Contain    calc_header.png    10
    # Kluczowe: Klikamy nagłówek i dajemy oknu czas na "wybudzenie się"
    Click    calc_header.png
    Sleep    1s
    Click    button_7.png
    Click    button_minus.png
    Click    button_5.png
    Click    equal.png
    Screen Should Contain    result_2.png
*** Test Cases ***
Multiplication In Calculator
    [Setup]       Add Image Path    ${IMAGE_PATH}
    [Teardown]    Reset Environment
    Start Process    ${APP}
    Wait Until Screen Contain    calc_header.png    10
    # Klikamy nagłówek i czekamy chwilę na fokus
    Click    calc_header.png
    Sleep    1s
    Click    button_7.png
    Click    multi.png
    Click    button_5.png
    Click    equal.png
    Screen Should Contain    result_35.png
*** Keywords ***
Reset Environment
    Set Min Similarity    0.90
    # Zamykamy procesy biblioteką
    Terminate All Processes
    # Wymuszamy zamknięcie przez system operacyjny
    Run Process    taskkill    /F    /IM    CalculatorApp.exe    /T    shell=True
    Run Process    taskkill    /F    /IM    calc.exe    /T    shell=True
    # Czekamy, aż Windows "zapomni" o starym kalkulatorze
    Sleep    2s