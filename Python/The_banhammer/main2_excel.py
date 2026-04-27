import os
import csv
import mysql.connector
from dotenv import load_dotenv
import pandas as pd
#pip install python-dotenv mysql-connector-python   pandas openpyxl
load_dotenv()
def append_new_rows_to_csv(filename: str, new_df: pd.DataFrame, key_columns=('id',)):
    """
    Logika:
    Dopisuje do CSV tylko nowe wiersze z new_df bazując na kolumnach key_columns.
    - Jeśli plik nie istnieje -> tworzy go i zapisuje wszystkie wiersze (z nagłówkiem).
    - Jeśli plik istnieje -> dopisuje tylko te wiersze, których kombinacja wartości w key_columns
      nie występuje jeszcze w pliku.
    """
    if new_df.empty:
        print("Brak danych do zapisania.")
        return
    for k in key_columns:
        if k not in new_df.columns:
            raise ValueError(f"Brak kolumny kluczowej w danych: {k}")
    file_exists = os.path.isfile(filename)
    if not file_exists:
        new_df.to_csv(filename, index=False, encoding='utf-8')
        print(f"Utworzono plik {filename} i zapisano {len(new_df)} wierszy.")
        return
    # Plik istnieje -> wczytaj istniejące klucze i porównaj
    existing_df = pd.read_csv(filename, dtype=str, encoding='utf-8')  # czytamy jako string by uniknąć problemów typów
    # Sprawdź, czy istniejące plik zawiera kluczowe kolumny
    for k in key_columns:
        if k not in existing_df.columns:
            # Jeśli plik istnieje, ale nie ma kolumny kluczowej -> traktujemy wszystkie wiersze jako nowe
            print(f"Uwaga: istniejący plik nie zawiera kolumny kluczowej '{k}'. Wszystkie wiersze będą traktowane jako nowe.")
            new_rows = new_df
            break
    else:
        existing_keys = existing_df[list(key_columns)].astype(str).agg('||'.join, axis=1)
        existing_key_set = set(existing_keys.values.tolist())
        new_keys_series = new_df[list(key_columns)].astype(str).agg('||'.join, axis=1)
        mask_new = ~new_keys_series.isin(existing_key_set)
        new_rows = new_df[mask_new]
    if new_rows.empty:
        print("Brak nowych unikalnych wierszy do dopisania.")
        return
    # Dopisz nowe wiersze (bez nagłówka)
    new_rows.to_csv(filename, mode='a', index=False, header=False, encoding='utf-8')
    print(f"Dopisano {len(new_rows)} nowych wierszy do {filename}.")
def fetch_data_from_db(query: str) -> pd.DataFrame:
    mydb = mysql.connector.connect(
        host=os.getenv('HOST_NAME'),
        user=os.getenv('DB_USER'),
        password=os.getenv('DB_PASSWORD'),
        database=os.getenv('DB_NAME')
    )
    mycursor = mydb.cursor()
    mycursor.execute(query)
    myresult = mycursor.fetchall()
    columns = [desc[0] for desc in mycursor.description]
    mycursor.close()
    mydb.close()
    return pd.DataFrame(myresult, columns=columns)
if __name__ == "__main__":
    query = "SELECT * FROM twfjqjet.test"  # dostosuj zapytanie do Twojej logiki
    df = fetch_data_from_db(query)
    append_new_rows_to_csv('usuniete_konta.csv', df, key_columns=('id',))
    df.to_excel('usuniete_konta.xlsx', index=False)
    print("Dane zapisane do usuniete_konta.xlsx")