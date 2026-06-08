*** Settings ***
Library    ImageHorizonLibrary    mode=NEW    timeout=10
Library    Process
Library    OperatingSystem
Suite Setup       Setup Horizon
Suite Teardown    Close Calculator

*** Variables ***
${CALCULATOR_EXE}       ${CURDIR}/calc.exe
${IMAGE_FOLDER}         ${CURDIR}/images

# Digit Buttons (Reusing Sikuli assets)
${BTN_0}                button_digit_0.png
${BTN_1}                button_digit_1.png
${BTN_2}                button_digit_2.png
${BTN_3}                button_digit_3.png
${BTN_4}                button_digit_4.png
${BTN_5}                button_digit_5.png
${BTN_6}                button_digit_6.png
${BTN_7}                button_digit_7.png
${BTN_8}                button_digit_8.png
${BTN_9}                button_digit_9.png

# Operation Buttons (Reusing Sikuli assets)
${BTN_ADD}              add.png
${BTN_SUB}              sub.png
${BTN_MULT}             mult.png
${BTN_DIV}              divide.png
${BTN_EQUAL}            equals.png

*** Test Cases ***
Addition In Calculator
    [Documentation]    Verifies that 2 + 2 equals 4.
    [Teardown]    Close Calculator
    Open Calculator
    Click Image Asset    ${BTN_2}
    Click Image Asset    ${BTN_ADD}
    Click Image Asset    ${BTN_2}
    Click Image Asset    ${BTN_EQUAL}
    Result Should Be    wynik_4.png

Subtraction In Calculator
    [Documentation]    Verifies that 7 - 5 equals 2.
    [Teardown]    Close Calculator
    Open Calculator
    Click Image Asset    ${BTN_7}
    Click Image Asset    ${BTN_SUB}
    Click Image Asset    ${BTN_5}
    Click Image Asset    ${BTN_EQUAL}
    Result Should Be    wynik_2.png

Multiplication In Calculator
    [Documentation]    Verifies that 6 * 7 equals 42.
    [Teardown]    Close Calculator
    Open Calculator
    Click Image Asset    ${BTN_6}
    Click Image Asset    ${BTN_MULT}
    Click Image Asset    ${BTN_7}
    Click Image Asset    ${BTN_EQUAL}
    Result Should Be    wynik_42.png

Division In Calculator
    [Documentation]    Verifies that 6 / 2 equals 3.
    [Teardown]    Close Calculator
    Open Calculator
    Click Image Asset    ${BTN_6}
    Click Image Asset    ${BTN_DIV}
    Click Image Asset    ${BTN_2}
    Click Image Asset    ${BTN_EQUAL}
    Result Should Be    wynik_3.png

*** Keywords ***
Setup Horizon
    Directory Should Exist    ${IMAGE_FOLDER}
    ${abs_image_path}=    Normalize Path    ${IMAGE_FOLDER}
    Set Reference Folder    ${abs_image_path}
    # Lowering confidence significantly as Sikuli used 0.30
    Set Confidence    0.50

Open Calculator
    # Clean up and start
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    # Use the local calc.exe
    Run Process    cmd.exe    /c    start /max ${CALCULATOR_EXE}
    Sleep    5s
    # Wait for a stable element to ensure app is ready
    Wait For    ${BTN_EQUAL}    timeout=30

Click Image Asset
    [Arguments]    ${image_name}
    Wait For    ${image_name}    timeout=15
    Click Image    ${image_name}
    Sleep    0.5s

Result Should Be
    [Arguments]    ${expected_result_image}
    Wait For    ${expected_result_image}    timeout=15

Close Calculator
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
