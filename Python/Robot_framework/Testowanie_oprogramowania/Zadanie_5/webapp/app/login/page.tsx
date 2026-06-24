"use client";

import { useState } from "react";
import { useRouter } from "next/navigation";

const VALID_EMAIL = "user@example.com";
const VALID_PASSWORD = "password123";

export default function LoginPage() {
  const router = useRouter();
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");
  const [success, setSuccess] = useState(false);

  function handleSubmit(e: React.FormEvent) {
    e.preventDefault();
    setError("");

    if (!email || !password) {
      setError("Wypełnij wszystkie pola.");
      return;
    }

    if (email === VALID_EMAIL && password === VALID_PASSWORD) {
      setSuccess(true);
      setTimeout(() => router.push("/todos"), 1500);
    } else {
      setError("Nieprawidłowy email lub hasło.");
    }
  }

  if (success) {
    return (
      <div
        className="max-w-md mx-auto text-center py-12"
        data-testid="login-success"
      >
        <p className="text-green-600 text-xl font-semibold">
          Zalogowano pomyślnie! Przekierowanie...
        </p>
      </div>
    );
  }

  return (
    <div className="max-w-md mx-auto">
      <h1 className="text-2xl font-bold text-gray-900 mb-6" data-testid="login-heading">
        Logowanie
      </h1>

      <form
        onSubmit={handleSubmit}
        className="bg-white rounded-lg shadow p-6 space-y-4"
        data-testid="login-form"
        noValidate
      >
        <div>
          <label
            htmlFor="email"
            className="block text-sm font-medium text-gray-700 mb-1"
          >
            Email
          </label>
          <input
            id="email"
            type="email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            className="w-full border border-gray-300 rounded-md px-3 py-2 focus:outline-none focus:ring-2 focus:ring-blue-500"
            placeholder="user@example.com"
            data-testid="input-email"
          />
        </div>

        <div>
          <label
            htmlFor="password"
            className="block text-sm font-medium text-gray-700 mb-1"
          >
            Hasło
          </label>
          <input
            id="password"
            type="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            className="w-full border border-gray-300 rounded-md px-3 py-2 focus:outline-none focus:ring-2 focus:ring-blue-500"
            placeholder="••••••••"
            data-testid="input-password"
          />
        </div>

        {error && (
          <p className="text-red-600 text-sm" data-testid="login-error">
            {error}
          </p>
        )}

        <button
          type="submit"
          className="w-full bg-blue-600 text-white py-2 px-4 rounded-md hover:bg-blue-700 transition-colors font-medium"
          data-testid="btn-submit"
        >
          Zaloguj się
        </button>

        <p className="text-xs text-gray-400 text-center">
          Testowe dane: user@example.com / password123
        </p>
      </form>
    </div>
  );
}
