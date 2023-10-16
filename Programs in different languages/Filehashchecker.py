import hashlib

def calculate_hash(file_path, hash_type='md5', buffer_size=65536):
    hash_function = hashlib.new(hash_type)
    with open(file_path, 'rb') as file:
        buffer = file.read(buffer_size)
        while len(buffer) > 0:
            hash_function.update(buffer)
            buffer = file.read(buffer_size)
    return hash_function.hexdigest()

def validate_file_hash(file_path, expected_hash, hash_type='md5'):
    try:
        calculated_hash = calculate_hash(file_path, hash_type)
        if calculated_hash == expected_hash:
            print(f"Validation successful! The {hash_type.upper()} hash of the file matches the provided hash.")
        else:
            print(f"Validation failed! The {hash_type.upper()} hash of the file does not match the provided hash.")
    except FileNotFoundError:
        print("Error: File not found.")
    except PermissionError:
        print("Error: Permission denied to access the file.")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    file_path = input("Enter the path to the file: ")
    expected_hash = input("Enter the expected hash value: ")
    hash_type = input("Enter the hash type (md5, sha1, or sha256): ").lower()
    
    validate_file_hash(file_path, expected_hash, hash_type)
