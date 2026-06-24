"use client";

import { useState } from "react";

interface Todo {
  id: number;
  text: string;
  completed: boolean;
}

let nextId = 1;

export default function TodosPage() {
  const [todos, setTodos] = useState<Todo[]>([]);
  const [input, setInput] = useState("");
  const [inputError, setInputError] = useState("");

  function addTodo() {
    const trimmed = input.trim();
    if (!trimmed) {
      setInputError("Wpisz treść zadania.");
      return;
    }
    setInputError("");
    setTodos((prev) => [...prev, { id: nextId++, text: trimmed, completed: false }]);
    setInput("");
  }

  function toggleTodo(id: number) {
    setTodos((prev) =>
      prev.map((t) => (t.id === id ? { ...t, completed: !t.completed } : t))
    );
  }

  function deleteTodo(id: number) {
    setTodos((prev) => prev.filter((t) => t.id !== id));
  }

  function handleKeyDown(e: React.KeyboardEvent<HTMLInputElement>) {
    if (e.key === "Enter") addTodo();
  }

  return (
    <div className="max-w-lg mx-auto space-y-6">
      <h1 className="text-2xl font-bold text-gray-900" data-testid="todos-heading">
        Lista Zadań
      </h1>

      <div className="flex gap-2">
        <input
          type="text"
          value={input}
          onChange={(e) => setInput(e.target.value)}
          onKeyDown={handleKeyDown}
          placeholder="Nowe zadanie..."
          className="flex-1 border border-gray-300 rounded-md px-3 py-2 focus:outline-none focus:ring-2 focus:ring-blue-500"
          data-testid="todo-input"
        />
        <button
          onClick={addTodo}
          className="bg-blue-600 text-white px-4 py-2 rounded-md hover:bg-blue-700 transition-colors font-medium"
          data-testid="btn-add-todo"
        >
          Dodaj
        </button>
      </div>

      {inputError && (
        <p className="text-red-600 text-sm" data-testid="todo-input-error">
          {inputError}
        </p>
      )}

      {todos.length === 0 ? (
        <p className="text-gray-400 text-center py-8" data-testid="todos-empty">
          Brak zadań. Dodaj pierwsze!
        </p>
      ) : (
        <ul className="space-y-2" data-testid="todos-list">
          {todos.map((todo) => (
            <li
              key={todo.id}
              className="flex items-center gap-3 bg-white rounded-lg shadow px-4 py-3 border border-gray-100"
              data-testid="todo-item"
            >
              <input
                type="checkbox"
                checked={todo.completed}
                onChange={() => toggleTodo(todo.id)}
                className="w-4 h-4 accent-blue-600 cursor-pointer"
                data-testid="todo-checkbox"
              />
              <span
                className={`flex-1 ${todo.completed ? "line-through text-gray-400" : "text-gray-800"}`}
                data-testid="todo-text"
              >
                {todo.text}
              </span>
              <button
                onClick={() => deleteTodo(todo.id)}
                className="text-red-500 hover:text-red-700 text-sm font-medium"
                data-testid="btn-delete-todo"
              >
                Usuń
              </button>
            </li>
          ))}
        </ul>
      )}

      {todos.length > 0 && (
        <p className="text-sm text-gray-500" data-testid="todos-count">
          {todos.filter((t) => t.completed).length} / {todos.length} ukończonych
        </p>
      )}
    </div>
  );
}
