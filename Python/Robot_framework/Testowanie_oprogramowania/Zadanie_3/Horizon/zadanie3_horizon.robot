*** Settings ***
Library    Horizon    mode=NEW    timeout=10
Library    Process
Library    OperatingSystem
Suite Setup       Configure Sikuli
Suite Teardown    Stop Sikuli Server

*** Variables ***
${CALCULATOR_APP}       calc.exe
${IMAGE_PATH}           ${CURDIR}${/}images
${IMAGE_FOLDER}         ${IMAGE_PATH}
${SCREENSHOT_FOLDER}    ${OUTPUT DIR}

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

${CALCULATOR_STARTED}   ${FALSE}
${SIKULI_STARTED}       ${FALSE}

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
Configure Sikuli
    Directory Should Exist    ${IMAGE_FOLDER}
    Start Sikuli Process
    Set Test Variable    ${SIKULI_STARTED}    ${TRUE}
    ${abs_image_path}=    Normalize Path    ${IMAGE_FOLDER}
    Add Image Path    ${abs_image_path}
    Set Capture Folder    ${SCREENSHOT_FOLDER}
    Set Min Similarity    0.70
    Set Timeout    30

Open Calculator Maximized
    # Clean up any existing instances
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    
    # Start calculator and wait for it to appear
    Run Process    cmd.exe    /c    start /max ${CALCULATOR_APP}
    Set Test Variable    ${CALCULATOR_STARTED}    ${TRUE}
    Sleep    3s
    Wait Until Screen Contain    ${BTN_EQUALS}    30

Execute Arithmetic Operation
    [Arguments]    ${val1}    ${op}    ${val2}    ${expected_result_image}
    Open Calculator Maximized
    Click Calculator Image    ${val1}
    Click Calculator Image    ${op}
    Click Calculator Image    ${val2}
    Click Calculator Image    ${BTN_EQUALS}
    
    # Verify result if the image exists
    ${result_exists}=    Run Keyword And Return Status    File Should Exist    ${IMAGE_FOLDER}${/}${expected_result_image}
    IF    ${result_exists}
        Wait Until Screen Contain    ${expected_result_image}    10
        Run Keyword And Ignore Error    Highlight    ${expected_result_image}    2
    ELSE
        Fail    Result image ${expected_result_image} not found in ${IMAGE_FOLDER}
    END
    
    Log    Operation Successful: Result ${expected_result_image} verified.
    Close Calculator

Click Calculator Image
    [Arguments]    ${image_name}
    Wait Until Screen Contain    ${image_name}    15
    Run Keyword And Ignore Error    Highlight    ${image_name}    1
    Click    ${image_name}
    Sleep    0.5s

Close Calculator
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    win32calc.exe    /F    /T
    Run Keyword And Ignore Error    Run Process    taskkill    /IM    calc.exe    /F    /T
    Set Test Variable    ${CALCULATOR_STARTED}    ${FALSE}

Stop Sikuli Server
    # Note: Using 'Stop Remote Server' assuming Horizon library handles it this way
    # If using local SikuliLibrary, this might vary.
    Run Keyword And Ignore Error    Stop Remote Server
    Set Test Variable    ${SIKULI_STARTED}    ${FALSE}
