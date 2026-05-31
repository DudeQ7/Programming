*** Settings ***
Library    SikuliLibrary    WITH NAME    Sikuli
Library    ImageHorizonLibrary    WITH NAME    Horizon
Library    Process
Suite Setup    Open Calculator
Suite Teardown    Close Calculator
Test Setup    Clear Calculator

*** Variables ***
${KCALC_CMD}    kcalc
${IMAGES}    ${CURDIR}${/}..${/}images
${TIMEOUT}    5
${IMG_WINDOW}    ${IMAGES}${/}kcalc_window.png
${BTN_0}    ${IMAGES}${/}btn_0.png
${BTN_1}    ${IMAGES}${/}btn_1.png
${BTN_2}    ${IMAGES}${/}btn_2.png
${BTN_3}    ${IMAGES}${/}btn_3.png
${BTN_4}    ${IMAGES}${/}btn_4.png
${BTN_5}    ${IMAGES}${/}btn_5.png
${BTN_6}    ${IMAGES}${/}btn_6.png
${BTN_7}    ${IMAGES}${/}btn_7.png
${BTN_8}    ${IMAGES}${/}btn_8.png
${BTN_9}    ${IMAGES}${/}btn_9.png
${BTN_PLUS}    ${IMAGES}${/}btn_plus.png
${BTN_MINUS}    ${IMAGES}${/}btn_minus.png
${BTN_MUL}    ${IMAGES}${/}btn_mul.png
${BTN_DIV}    ${IMAGES}${/}btn_div.png
${BTN_EQ}    ${IMAGES}${/}btn_eq.png
${BTN_CLEAR}    ${IMAGES}${/}btn_clear.png
${DISP_5}    ${IMAGES}${/}display_5.png
${DISP_42}    ${IMAGES}${/}display_42.png
${DISP_4}    ${IMAGES}${/}display_4.png
${DISP_ERROR_DIV0}    ${IMAGES}${/}display_div0.png

*** Test Cases ***
Addition 2 + 3 = 5
    Press Button    ${BTN_2}
    Press Button    ${BTN_PLUS}
    Press Button    ${BTN_3}
    Press Button    ${BTN_EQ}
    Expect Display    ${DISP_5}

Subtraction 9 - 4 = 5
    Press Button    ${BTN_9}
    Press Button    ${BTN_MINUS}
    Press Button    ${BTN_4}
    Press Button    ${BTN_EQ}
    Expect Display    ${DISP_5}

Multiplication 6 * 7 = 42
    Press Button    ${BTN_6}
    Press Button    ${BTN_MUL}
    Press Button    ${BTN_7}
    Press Button    ${BTN_EQ}
    Expect Display    ${DISP_42}

Division 8 / 2 = 4
    Press Button    ${BTN_8}
    Press Button    ${BTN_DIV}
    Press Button    ${BTN_2}
    Press Button    ${BTN_EQ}
    Expect Display    ${DISP_4}

Division by zero shows error
    Press Button    ${BTN_5}
    Press Button    ${BTN_DIV}
    Press Button    ${BTN_0}
    Press Button    ${BTN_EQ}
    Expect Display    ${DISP_ERROR_DIV0}

*** Keywords ***
Open Calculator
    ${handle}=    Start Process    ${KCALC_CMD}
    Set Suite Variable    ${KCALC_HANDLE}    ${handle}
    Sikuli.Wait Until Screen Contain    ${IMG_WINDOW}    ${TIMEOUT}

Close Calculator
    Terminate Process    ${KCALC_HANDLE}

Clear Calculator
    Press Button    ${BTN_CLEAR}

Press Button
    [Arguments]    ${image}
    Sikuli.Wait Until Screen Contain    ${image}    ${TIMEOUT}
    Sikuli.Click    ${image}

Expect Display
    [Arguments]    ${image}
    Wait Until Keyword Succeeds    ${TIMEOUT}    200ms    Horizon.Image Should Exist    ${image}
