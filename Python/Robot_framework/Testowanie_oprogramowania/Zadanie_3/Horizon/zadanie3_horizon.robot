*** Settings *** 
Library    ImageHorizonLibrary
Library    Process
Suite Setup    Set Confidence    0.58

*** Variables *** 
${APP}    ${CURDIR}${/}calc.exe
${IMAGE_FOLDER}    ${CURDIR}${/}images
${SCREENSHOT_FOLDER}    ${OUTPUT DIR}

*** Test Cases ***
Test Dodawania Horizon

    Start Process    ${APP}

    Set Reference Folder    ${IMAGE_FOLDER}

    Sleep    5s

    Click Image    siedem.png
    Click Image    plus.png
    Click Image    siedem.png
    Click Image    rownosc.png

    Sleep    2s


Test Odejmowania Horizon

    Start Process    ${APP}

    Set Reference Folder    ${IMAGE_FOLDER}

    Sleep    5s

    Click Image    siedem.png
    Click Image    minus.png
    Click Image    siedem.png
    Click Image    rownosc.png

    Sleep    2s


Test Mnozenia Horizon

    Start Process    ${APP}

    Set Reference Folder    ${IMAGE_FOLDER}

    Sleep    5s

    Click Image    siedem.png
    Click Image    mnozenie.png
    Click Image    siedem.png
    Click Image    rownosc.png

    Sleep    2s


Test Dzielenia Horizon

    Start Process    ${APP}

    Set Reference Folder    ${IMAGE_FOLDER}

    Sleep    5s

    Click Image    siedem.png
    Click Image    dziel.png
    Click Image    siedem.png
    Click Image    rownosc.png

    Wait For    przycisk_1.png