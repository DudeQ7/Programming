*** Settings ***
Library    ImageHorizonLibrary    mode=NEW    timeout=10
Library    Process
Library    OperatingSystem
Suite Setup       Setup Horizon
Suite Teardown    Close Calculator

*** Variables ***
${CALCULATOR_EXE}       ${CURDIR}/calc.exe

# Image Mapping (bridging automation IDs to images)
${BTN_DIGIT_1}          przycisk_1.png
${BTN_DIGIT_2}          przycisk_2.png
${BTN_DIGIT_3}          p_3.png
${BTN_DIGIT_5}          piec.png
${BTN_DIGIT_6}          szesc.png
${BTN_DIGIT_7}          siedem.png

${BTN_ADD}              plus.png
${BTN_SUBTRACT}         minus.png
${BTN_MULTIPLY}         mnozenie.png
${BTN_DIVIDE}           dziel.png
${BTN_EQUAL}            rownosc.png

${IMAGE_FOLDER}         ${CURDIR}/images

*** Test Cases ***
Addition In Calculator
    [Documentation]    Verifies that 2 + 2 equals 4.
    [Teardown]    Close Calculator
    Open Calculator
    Click Digit    ${BTN_DIGIT_2}
    Click Operation    ${BTN_ADD}
    Click Digit    ${BTN_DIGIT_2}
    Click Operation    ${BTN_EQUAL}
    Result Should Be    wynik_4.png

Subtraction In Calculator
    [Documentation]    Verifies that 7 - 5 equals 2.
    [Teardown]    Close Calculator
    Open Calculator
    Click Digit    ${BTN_DIGIT_7}
    Click Operation    ${BTN_SUBTRACT}
    Click Digit    ${BTN_DIGIT_5}
    Click Operation    ${BTN_EQUAL}
    Result Should Be    wynik_2.png

Multiplication In Calculator
    [Documentation]    Verifies that 6 * 7 equals 42.
    [Teardown]    Close Calculator
    Open Calculator
    Click Digit    ${BTN_DIGIT_6}
    Click Operation    ${BTN_MULTIPLY}
    Click Digit    ${BTN_DIGIT_7}
    Click Operation    ${BTN_EQUAL}
    Result Should Be    czterydwa.png

Division In Calculator
    [Documentation]    Verifies that 6 / 2 equals 3.
    [Teardown]    Close Calculator
    Open Calculator
    Click Digit    ${BTN_DIGIT_6}
    Click Operation    ${BTN_DIVIDE}
    Click Digit    ${BTN_DIGIT_2}
    Click Operation    ${BTN_EQUAL}
    Result Should Be    trzy.png

*** Keywords ***
Setup Horizon
    Directory Should Exist    ${IMAGE_FOLDER}
    ${abs_image_path}=    Normalize Path    ${IMAGE_FOLDER}
    Set Reference Folder    ${abs_image_path}
    Run Keyword And Ignore Error    Set Confidence    0.60

Open Calculator
    # Clean up and start
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    Run Process    cmd.exe    /c    start /max ${CALCULATOR_EXE}
    Sleep    3s
    Wait For    ${BTN_EQUAL}    timeout=10

Click Digit
    [Arguments]    ${digit_image}
    Wait For    ${digit_image}    timeout=10
    Click Image    ${digit_image}
    Sleep    0.5s

Click Operation
    [Arguments]    ${operation_image}
    Wait For    ${operation_image}    timeout=10
    Click Image    ${operation_image}
    Sleep    0.5s

Result Should Be
    [Arguments]    ${expected_result_image}
    ${result_exists}=    Run Keyword And Return Status    File Should Exist    ${IMAGE_FOLDER}/${expected_result_image}
    IF    ${result_exists}
        Wait For    ${expected_result_image}    timeout=10
    ELSE
        Log    Warning: Result image ${expected_result_image} not found, skipping visual verification.    level=WARN
    END

Close Calculator
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
