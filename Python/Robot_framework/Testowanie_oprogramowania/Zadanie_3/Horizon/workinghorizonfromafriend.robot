*** Settings *** 
Library    ImageHorizonLibrary
Library    Process

*** Variables *** 
${APP}    ${CURDIR}${/}calc.exe
${IMAGE_FOLDER}    ${CURDIR}${/}images
${SCREENSHOT_FOLDER}    ${OUTPUT DIR}

*** Test Cases *** 


Test Dodawania Horizon

    Start Process    ${APP}

    Set Reference Folder    ${IMAGE_FOLDER}
    Run Keyword And Ignore Error    Set Confidence    0.8

    Sleep    5s

    Click Image    6_2.png
    Click Image    plus.png
    Click Image    przycisk_2.png
    Click Image    rownosc.png

    Wait For    trzy.png


Test Odejmowania Horizon

    Start Process    ${APP}

    Set Reference Folder    ${IMAGE_FOLDER}
    Run Keyword And Ignore Error    Set Confidence    0.8

    Sleep    5s

    Click Image    piec.png
    Click Image    minus.png
    Click Image    przycisk_1.png
    Click Image    rownosc.png

    Wait For    wynik_4.png


Test Mnozenia Horizon

    Start Process    ${APP}

    Set Reference Folder    ${IMAGE_FOLDER}
    Run Keyword And Ignore Error    Set Confidence    0.8

    Sleep    5s

    Click Image    szesc.png
    Click Image    mnozenie.png
    Click Image    siedem.png
    Click Image    rownosc.png

    Wait For    czterydwa.png


Test Dzielenia Horizon

    Start Process    ${APP}

    Set Reference Folder    ${IMAGE_FOLDER}
    Run Keyword And Ignore Error    Set Confidence    0.8

    Sleep    5s

    Click Image    szesc.png
    Click Image    dziel.png
    Click Image    p_3.png
    Click Image    rownosc.png

    Wait For    wynik_2.png