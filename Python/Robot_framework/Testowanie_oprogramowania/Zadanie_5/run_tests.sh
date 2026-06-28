#!/usr/bin/env bash
cd "$(dirname "$0")"
source .venv/bin/activate
pytest test_kalkulator.py -v --headed
