import pytest
from pathlib import Path
from playwright.sync_api import Page

KALKULATOR_URL = Path(__file__).parent.resolve().as_uri() + "/kalkulator.html"


@pytest.fixture(autouse=True)
def otworz_kalkulator(page: Page):
    page.goto(KALKULATOR_URL)
    page.wait_for_selector("#display")
    yield
    page.wait_for_timeout(2000)
    page.locator("#btn-ac").click()


@pytest.hookimpl(hookwrapper=True)
def pytest_runtest_makereport(item, call):
    outcome = yield
    rep = outcome.get_result()
    if rep.when == "call":
        doc = getattr(item.function, "__doc__", None)
        if doc:
            rep.nodeid = doc.strip()
