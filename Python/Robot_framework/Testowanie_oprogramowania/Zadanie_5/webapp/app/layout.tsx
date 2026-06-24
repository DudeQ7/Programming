import type { Metadata } from "next";
import Link from "next/link";
import "./globals.css";

export const metadata: Metadata = {
  title: "Testowa Aplikacja",
  description: "Aplikacja do testowania Playwright",
};

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="pl" className="h-full">
      <body className="min-h-full flex flex-col bg-gray-50">
        <nav className="bg-white shadow-sm border-b border-gray-200">
          <div className="max-w-4xl mx-auto px-4 py-3 flex gap-6 items-center">
            <Link
              href="/"
              className="text-lg font-bold text-blue-600 hover:text-blue-800"
              data-testid="nav-home"
            >
              Strona Główna
            </Link>
            <Link
              href="/login"
              className="text-gray-600 hover:text-gray-900"
              data-testid="nav-login"
            >
              Logowanie
            </Link>
            <Link
              href="/todos"
              className="text-gray-600 hover:text-gray-900"
              data-testid="nav-todos"
            >
              Lista Zadań
            </Link>
          </div>
        </nav>
        <main className="flex-1 max-w-4xl mx-auto w-full px-4 py-8">
          {children}
        </main>
      </body>
    </html>
  );
}
