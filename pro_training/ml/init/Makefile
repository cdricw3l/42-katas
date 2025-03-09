run:
	@time python3 project/main.py

venv:
	python3 -m venv venv

clean:
	rm -rf venv

install: requirements.txt
	pip install -r requirements.txt

re: clean venv install