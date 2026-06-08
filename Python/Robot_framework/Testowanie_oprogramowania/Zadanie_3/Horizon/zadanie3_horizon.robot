*** Settings ***
Library    ImageHorizonLibrary
Library    Process

*** Variables ***
${APP}    calc.exe
${IMAGE_PATH}    ${CURDIR}${/}images
${IMAGE_FOLDER}    ${IMAGE_PATH}

*** Test Cases ***

Test mnozenia 7x7
    Run Process    cmd.exe    /c    start /max ${APP}
    Sleep    3s
    Set Reference Folder    ${IMAGE_FOLDER}
    Set Confidence    0.52
    Wait For    siedem.png    timeout=20
    Click Image    siedem.png
    Set Confidence    0.58
    Click Image    mnozenie.png
    Set Confidence    0.52
    Click Image    siedem.png
    Set Confidence    0.58
    Click Image    rownosc.png
    Wait For    wynik_49.png    timeout=15

Test dzielenia 7/7
    Run Process    cmd.exe    /c    start /max ${APP}
    Sleep    3s
    Set Reference Folder    ${IMAGE_FOLDER}
    Set Confidence    0.52
    Wait For    siedem.png    timeout=20
    Click Image    siedem.png
    Set Confidence    0.58
    Click Image    dziel.png
    Set Confidence    0.52
    Click Image    siedem.png
    Set Confidence    0.58
    Click Image    rownosc.png
    Wait For    przycisk_1.png    timeout=15


