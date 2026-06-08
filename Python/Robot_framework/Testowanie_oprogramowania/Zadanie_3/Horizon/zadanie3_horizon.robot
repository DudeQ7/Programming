*** Settings ***
Library    ImageHorizonLibrary    mode=NEW    timeout=10
Library    Process
Library    OperatingSystem
Suite Setup       Setup Horizon
Suite Teardown    Close Calculator

*** Variables ***
${CALCULATOR_APP}       calc.exe
${IMAGE_PATH}           ${CURDIR}${/}images
${IMAGE_FOLDER}         ${IMAGE_PATH}

# Digit Buttons
${BTN_1}                przycisk_1.png
${BTN_2}                przycisk_2.png
${BTN_3}                p_3.png
${BTN_5}                piec.png
${BTN_6}                szesc.png
${BTN_7}                siedem.png

# Operation Buttons
${BTN_ADD}              plus.png
${BTN_SUB}              minus.png
${BTN_MULT}             mnozenie.png
${BTN_DIV}              dziel.png
${BTN_EQUALS}           rownosc.png

*** Test Cases ***
Test Subtraction 7 - 5 = 2
    [Documentation]    Verifies that 7 - 5 equals 2.
    Execute Arithmetic Operation    ${BTN_7}    ${BTN_SUB}    ${BTN_5}    wynik_2.png

Test Subtraction 7 - 3 = 4
    [Documentation]    Verifies that 7 - 3 equals 4.
    Execute Arithmetic Operation    ${BTN_7}    ${BTN_SUB}    ${BTN_3}    wynik_4.png

Test Multiplication 6 * 7 = 42
    [Documentation]    Verifies that 6 * 7 equals 42.
    Execute Arithmetic Operation    ${BTN_6}    ${BTN_MULT}    ${BTN_7}    czterydwa.png

Test Division 6 / 2 = 3
    [Documentation]    Verifies that 6 / 2 equals 3.
    Execute Arithmetic Operation    ${BTN_6}    ${BTN_DIV}    ${BTN_2}    trzy.png

*** Keywords ***
Setup Horizon
    Directory Should Exist    ${IMAGE_FOLDER}
    ${abs_image_path}=    Normalize Path    ${IMAGE_FOLDER}
    # Using official ImageHorizonLibrary keywords
    Set Reference Folder    ${abs_image_path}
    Run Keyword And Ignore Error    Set Confidence    0.60

Open Calculator Maximized
    # Clean up any existing instances
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    
    # Start calculator
    Run Process    cmd.exe    /c    start /max ${CALCULATOR_APP}
    Sleep    3s
    Wait For    ${BTN_EQUALS}    timeout=10

Execute Arithmetic Operation
    [Arguments]    ${val1}    ${op}    ${val2}    ${expected_result_image}
    Open Calculator Maximized
    
    Click Horizon Image    ${val1}
    Click Horizon Image    ${op}
    Click Horizon Image    ${val2}
    Click Horizon Image    ${BTN_EQUALS}
    
    # Verify result
    ${result_exists}=    Run Keyword And Return Status    File Should Exist    ${IMAGE_FOLDER}${/}${expected_result_image}
    IF    ${result_exists}
        Wait For    ${expected_result_image}    timeout=10
    ELSE
        Fail    Result image ${expected_result_image} not found in ${IMAGE_FOLDER}
    END
    
    Log    Operation Successful: Result ${expected_result_image} verified.
    Close Calculator

Click Horizon Image
    [Arguments]    ${image_name}
    Wait For    ${image_name}    timeout=10
    Click Image    ${image_name}
    Sleep    0.5s

Close Calculator
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
