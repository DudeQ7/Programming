import { test, expect } from '@playwright/test';

test.describe('Strona Logowania', () => {
  test.beforeEach(async ({ page }) => {
    await page.goto('/login');
    await page.waitForLoadState('networkidle');
  });

  test('wyświetla formularz logowania', async ({ page }) => {
    await expect(page.getByTestId('login-heading')).toHaveText('Logowanie');
    await expect(page.getByTestId('login-form')).toBeVisible();
    await expect(page.getByTestId('input-email')).toBeVisible();
    await expect(page.getByTestId('input-password')).toBeVisible();
    await expect(page.getByTestId('btn-submit')).toBeVisible();
  });

  test('pokazuje błąd gdy pola są puste', async ({ page }) => {
    await page.getByTestId('btn-submit').click();
    await expect(page.getByTestId('login-error')).toBeVisible();
    await expect(page.getByTestId('login-error')).toHaveText('Wypełnij wszystkie pola.');
  });

  test('pokazuje błąd gdy tylko email jest wypełniony', async ({ page }) => {
    await page.getByTestId('input-email').fill('user@example.com');
    await page.getByTestId('btn-submit').click();
    await expect(page.getByTestId('login-error')).toBeVisible();
  });

  test('pokazuje błąd przy złych danych logowania', async ({ page }) => {
    await page.getByTestId('input-email').fill('zly@email.com');
    await page.getByTestId('input-password').fill('zlehaslo');
    await page.getByTestId('btn-submit').click();
    await expect(page.getByTestId('login-error')).toBeVisible();
    await expect(page.getByTestId('login-error')).toHaveText('Nieprawidłowy email lub hasło.');
  });

  test('pokazuje błąd przy poprawnym emailu ale złym haśle', async ({ page }) => {
    await page.getByTestId('input-email').fill('user@example.com');
    await page.getByTestId('input-password').fill('zlehaslo');
    await page.getByTestId('btn-submit').click();
    await expect(page.getByTestId('login-error')).toHaveText('Nieprawidłowy email lub hasło.');
  });

  test('pomyślne logowanie z poprawnymi danymi', async ({ page }) => {
    await page.getByTestId('input-email').fill('user@example.com');
    await page.getByTestId('input-password').fill('password123');
    await page.getByTestId('btn-submit').click();
    await expect(page.getByTestId('login-success')).toBeVisible();
    await expect(page.getByTestId('login-success')).toContainText('Zalogowano pomyślnie');
  });

  test('po pomyślnym logowaniu następuje przekierowanie na /todos', async ({ page }) => {
    await page.getByTestId('input-email').fill('user@example.com');
    await page.getByTestId('input-password').fill('password123');
    await page.getByTestId('btn-submit').click();
    await expect(page).toHaveURL('/todos', { timeout: 5000 });
  });

  test('pole email akceptuje wpisany tekst', async ({ page }) => {
    await page.getByTestId('input-email').fill('test@test.com');
    await expect(page.getByTestId('input-email')).toHaveValue('test@test.com');
  });

  test('pole hasła ma type="password"', async ({ page }) => {
    await expect(page.getByTestId('input-password')).toHaveAttribute('type', 'password');
  });
});
