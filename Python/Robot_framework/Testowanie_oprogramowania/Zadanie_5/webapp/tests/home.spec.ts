import { test, expect } from '@playwright/test';

test.describe('Strona Główna', () => {
  test.beforeEach(async ({ page }) => {
    await page.goto('/');
  });

  test('wyświetla poprawny tytuł strony', async ({ page }) => {
    await expect(page).toHaveTitle(/Testowa Aplikacja/);
  });

  test('wyświetla nagłówek powitalny', async ({ page }) => {
    await expect(page.getByTestId('home-heading')).toBeVisible();
    await expect(page.getByTestId('home-heading')).toHaveText('Witaj w Testowej Aplikacji');
  });

  test('wyświetla opis aplikacji', async ({ page }) => {
    await expect(page.getByTestId('home-description')).toBeVisible();
  });

  test('wyświetla kartę logowania i kartę zadań', async ({ page }) => {
    await expect(page.getByTestId('card-login')).toBeVisible();
    await expect(page.getByTestId('card-todos')).toBeVisible();
  });

  test('nawigacja — kliknięcie karty logowania przenosi na /login', async ({ page }) => {
    await page.getByTestId('card-login').click();
    await expect(page).toHaveURL('/login');
  });

  test('nawigacja — kliknięcie karty zadań przenosi na /todos', async ({ page }) => {
    await page.getByTestId('card-todos').click();
    await expect(page).toHaveURL('/todos');
  });

  test('nawigacja — linki w pasku nawigacji są widoczne', async ({ page }) => {
    await expect(page.getByTestId('nav-home')).toBeVisible();
    await expect(page.getByTestId('nav-login')).toBeVisible();
    await expect(page.getByTestId('nav-todos')).toBeVisible();
  });

  test('nawigacja — link do logowania w nav bar działa', async ({ page }) => {
    await page.getByTestId('nav-login').click();
    await expect(page).toHaveURL('/login');
  });
});
