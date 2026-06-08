*** Settings ***
Library    ImageHorizonLibrary
Library    Process

*** Variables ***
${APP}    ${CURDIR}${/}calc.exe
${IMAGE_FOLDER}    ${CURDIR}${/}images

*** Test Cases ***
Addition Stable
    [Documentation]    Stable test using 1 + 2 = 3
    Run Process    cmd.exe    /c    start /max ${APP}
    Sleep    3s
    Set Reference Folder    ${IMAGE_FOLDER}
    Set Confidence    0.58
    Click Image    przycisk_1.png
    Click Image    plus.png
    Click Image    przycisk_2.png
    Click Image    rownosc.png
    Wait For    trzy.png    timeout=10

Subtraction Stable
    [Documentation]    Stable test using 2 - 1 = 1
    Run Process    cmd.exe    /c    start /max ${APP}
    Sleep    3s
    Set Reference Folder    ${IMAGE_FOLDER}
    Set Confidence    0.58
    Click Image    przycisk_2.png
    Click Image    minus.png
    Click Image    przycisk_1.png
    Click Image    rownosc.png
    Wait For    przycisk_1.png    timeout=10
