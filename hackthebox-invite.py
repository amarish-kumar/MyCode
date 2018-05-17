import requests

page = requests.post('https://www.hackthebox.eu/api/invite/generate', data=None, json=None)
print(page.text)