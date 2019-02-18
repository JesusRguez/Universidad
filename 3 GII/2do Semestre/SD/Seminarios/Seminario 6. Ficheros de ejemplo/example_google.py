from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive
import os
import tempfile

gauth = GoogleAuth()
credentials = "mycreds.txt"

if not os.path.exists(credentials):
    gauth.LocalWebserverAuth() # Creates local webserver and auto handles authentication.
    # Save the current credentials to a file
    gauth.SaveCredentialsFile(credentials)
else:
    gauth.LoadCredentialsFile(credentials)

drive = GoogleDrive(gauth)
files = drive.ListFile().GetList()

file_names = [file['title'] for file in files]
print(file_names)

if "example_google.py" not in file_names:
    file_remote = drive.CreateFile({'title': "example_google.py"})
    file_remote.SetContentFile("example.py")
    print("Subiendo")
    file_remote.Upload()
    print("Subido")
else:
    print("Found")

excel_file = drive.ListFile({'q': 'title contains ".xlsx"'}).GetList()

if len(excel_file) > 1:
    file_download = excel_file[0]
    file_temp = tempfile.NamedTemporaryFile(suffix=".xslx")
    file_download.GetContentFile(file_temp.name)
    print("Downloaded drive:" +file_download['title']+" -> local:" +file_temp.name)
