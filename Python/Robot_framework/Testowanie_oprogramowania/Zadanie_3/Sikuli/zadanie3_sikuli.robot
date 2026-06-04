*** Settings ***
Library           SikuliLibrary
Library           Process
*** Variables ***
${IMAGE_PATH}     ${CURDIR}/images/
${APP}            calc.exe
*** Test Cases ***
Addition In Calculator
    [Setup]       Add Image Path    ${IMAGE_PATH}
    [Teardown]    Terminate All Processes
    Start Process    ${APP}
    Wait Until Screen Contain    calc_header.png    10
    Click    calc_header.png
    Click    button_5.png
    Click    button_plus.png
    Click    button_3.png
    Click    equal.png
    Screen Should Contain    result_8.png