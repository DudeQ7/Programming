import Link from "next/link";

export default function HomePage() {
  return (
    <div className="space-y-8">
      <section>
        <h1
          className="text-3xl font-bold text-gray-900 mb-2"
          data-testid="home-heading"
        >
          Witaj w Testowej Aplikacji
        </h1>
        <p className="text-gray-600" data-testid="home-description">
          Prosta aplikacja stworzona do nauki testowania E2E z użyciem Playwright.
        </p>
      </section>

      <section className="grid grid-cols-1 md:grid-cols-2 gap-4">
        <Link
          href="/login"
          className="block p-6 bg-white rounded-lg shadow hover:shadow-md border border-gray-200 transition-shadow"
          data-testid="card-login"
        >
          <h2 className="text-xl font-semibold text-blue-600 mb-2">Logowanie</h2>
          <p className="text-gray-600 text-sm">
            Formularz logowania z walidacją pól i obsługą błędów.
          </p>
        </Link>

        <Link
          href="/todos"
          className="block p-6 bg-white rounded-lg shadow hover:shadow-md border border-gray-200 transition-shadow"
          data-testid="card-todos"
        >
          <h2 className="text-xl font-semibold text-blue-600 mb-2">Lista Zadań</h2>
          <p className="text-gray-600 text-sm">
            Dodawaj, zaznaczaj i usuwaj zadania z dynamicznej listy.
          </p>
        </Link>
      </section>
    </div>
  );
}
