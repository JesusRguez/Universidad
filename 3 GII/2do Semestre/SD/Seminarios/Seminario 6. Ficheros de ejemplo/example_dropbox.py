import dropbox
import tempfile

token = "uSoGb4uOxxYAAAAAAAADaw1AkRCzi25FnCJSs69B2c4Lna5tx2vkcG0mSM6F4tcV"
dbx = dropbox.Dropbox(token)
user = dbx.users_get_current_account()

files = dbx.files_list_folder("")

for file in files.entries:
    print(file.name, file.size)

file_names = [file.name for file in files.entries]

if "examplev2.py" not in file_names:

    with open("example_token.py", "rb") as f:
        data = f.read()

    print("Subiendo")
    response2 = dbx.files_upload(data, "/examplev2.py", mute=True)
    print('uploaded2: ', response2)

excel_file = [fname for fname in file_names if ".xslx" in fname]

if len(excel_file) == 1:
    path = "/" +excel_file[0]
    print(path)
    file_temp = tempfile.NamedTemporaryFile(suffix=".xslx")
    dbx.files_download_to_file(file_temp.name, path)
    print("Downloaded dropbox:" +path +" -> local:" +file_temp.name)
 
