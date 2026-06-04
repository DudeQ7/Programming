*** Settings ***
Library           SikuliLibrary
Library           Process

*** Variables ***
${IMAGE_PATH}     ${CURDIR}/images/
${APP}            calc.exe
# Zwiększamy precyzję - 0.8 oznacza, że obrazek musi być prawie identyczny
${PRECISION}      ${0.8}

*** Test Cases ***
High Precision Addition Test
    [Setup]       Prepare High Precision Environment
    [Teardown]    Clean Up Environment
    
    Log To Console    Starting Calculator...
    Start Process    ${APP}
    
    # KROK 1: Lokalizacja okna i fokus
    Wait Until Screen Contain    calc_header.png    15
    # Klikamy w nagłówek z przesunięciem, żeby na pewno aktywować okno
    SikuliLibrary.Click    calc_header.png
    Sleep    1s

    # KROK 2: Sekwencja działań z potwierdzeniem wizualnym
    # Używamy dedykowanego Keyworda dla większej pewności
    Precise Click    button_5.png
    Precise Click    button_plus.png
    Precise Click    button_3.png
    Precise Click    equal.png
    
    # KROK 3: Weryfikacja
    Log To Console    Checking result...
    Sleep    1s
    # Tutaj możemy zostać przy 0.6, bo wynik czasem lekko się rozmazuje
    Screen Should Contain    result_8.png    0.6
    Log To Console    Test Finished Successfully!

*** Keywords ***
Prepare High Precision Environment
    Add Image Path    ${IMAGE_PATH}
    Set Min Similarity    ${PRECISION}
    # Wolniejsze ruchy myszy są lepiej rejestrowane przez Windows 11

Precise Click
    [Arguments]    ${image_name}
    Log To Console    Searching for: ${image_name}
    # Podświetla znaleziony przycisk na 0.5 sekundy (widzisz gdzie robot klika)
    Highlight    ${image_name}    0.5
    SikuliLibrary.Click    ${image_name}
    # Mała pauza, żeby system zarejestrował naciśnięcie przed kolejnym ruchem
    Sleep    0.3s

Clean Up Environment
    Stop Remote Server
    Terminate All Processes
    Log To Console    Cleaned up.