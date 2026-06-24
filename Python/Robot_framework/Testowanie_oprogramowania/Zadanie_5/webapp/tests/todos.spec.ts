import { test, expect } from '@playwright/test';

test.describe('Lista Zadań', () => {
  test.beforeEach(async ({ page }) => {
    await page.goto('/todos');
    await page.waitForLoadState('networkidle');
  });

  test('wyświetla nagłówek i puste pole input', async ({ page }) => {
    await expect(page.getByTestId('todos-heading')).toHaveText('Lista Zadań');
    await expect(page.getByTestId('todo-input')).toBeVisible();
    await expect(page.getByTestId('btn-add-todo')).toBeVisible();
  });

  test('wyświetla komunikat o braku zadań na początku', async ({ page }) => {
    await expect(page.getByTestId('todos-empty')).toBeVisible();
    await expect(page.getByTestId('todos-empty')).toContainText('Brak zadań');
  });

  test('pokazuje błąd przy próbie dodania pustego zadania', async ({ page }) => {
    await page.getByTestId('btn-add-todo').click();
    await expect(page.getByTestId('todo-input-error')).toBeVisible();
    await expect(page.getByTestId('todo-input-error')).toHaveText('Wpisz treść zadania.');
  });

  test('dodaje nowe zadanie', async ({ page }) => {
    await page.getByTestId('todo-input').fill('Nauczyć się Playwright');
    await page.getByTestId('btn-add-todo').click();
    await expect(page.getByTestId('todos-empty')).not.toBeVisible();
    await expect(page.getByTestId('todo-text').first()).toHaveText('Nauczyć się Playwright');
  });

  test('dodaje zadanie klawiszem Enter', async ({ page }) => {
    await page.getByTestId('todo-input').fill('Zadanie przez Enter');
    await page.getByTestId('todo-input').press('Enter');
    await expect(page.getByTestId('todo-text').first()).toHaveText('Zadanie przez Enter');
  });

  test('czyści pole input po dodaniu zadania', async ({ page }) => {
    await page.getByTestId('todo-input').fill('Testowe zadanie');
    await page.getByTestId('btn-add-todo').click();
    await expect(page.getByTestId('todo-input')).toHaveValue('');
  });

  test('dodaje wiele zadań', async ({ page }) => {
    await page.getByTestId('todo-input').fill('Zadanie pierwsze');
    await page.getByTestId('btn-add-todo').click();
    await page.getByTestId('todo-input').fill('Zadanie drugie');
    await page.getByTestId('btn-add-todo').click();
    await page.getByTestId('todo-input').fill('Zadanie trzecie');
    await page.getByTestId('btn-add-todo').click();

    const items = page.getByTestId('todo-item');
    await expect(items).toHaveCount(3);
  });

  test('zaznacza zadanie jako ukończone', async ({ page }) => {
    await page.getByTestId('todo-input').fill('Zadanie do zaznaczenia');
    await page.getByTestId('btn-add-todo').click();

    await page.getByTestId('todo-checkbox').first().click();
    await expect(page.getByTestId('todo-checkbox').first()).toBeChecked();
    await expect(page.getByTestId('todo-text').first()).toHaveClass(/line-through/);
  });

  test('odznacza ukończone zadanie', async ({ page }) => {
    await page.getByTestId('todo-input').fill('Zadanie do odznaczenia');
    await page.getByTestId('btn-add-todo').click();

    await page.getByTestId('todo-checkbox').first().click();
    await page.getByTestId('todo-checkbox').first().click();
    await expect(page.getByTestId('todo-checkbox').first()).not.toBeChecked();
  });

  test('usuwa zadanie', async ({ page }) => {
    await page.getByTestId('todo-input').fill('Zadanie do usunięcia');
    await page.getByTestId('btn-add-todo').click();
    await expect(page.getByTestId('todo-item')).toHaveCount(1);

    await page.getByTestId('btn-delete-todo').first().click();
    await expect(page.getByTestId('todos-empty')).toBeVisible();
  });

  test('wyświetla licznik ukończonych zadań', async ({ page }) => {
    await page.getByTestId('todo-input').fill('Zadanie A');
    await page.getByTestId('btn-add-todo').click();
    await page.getByTestId('todo-input').fill('Zadanie B');
    await page.getByTestId('btn-add-todo').click();

    await page.getByTestId('todo-checkbox').first().check();
    await expect(page.getByTestId('todos-count')).toContainText('1 / 2 ukończonych');
  });
});
