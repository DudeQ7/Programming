import pytest
from pathlib import Path
from playwright.sync_api import Page

KALKULATOR_URL = Path(__file__).parent.resolve().as_uri() + "/kalkulator.html"


@pytest.fixture(autouse=True)
def otworz_kalkulator(page: Page):
    page.goto(KALKULATOR_URL)
    page.wait_for_selector("#display")
    yield
    page.locator("#btn-ac").click()
