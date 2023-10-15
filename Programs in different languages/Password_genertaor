import random

def generate_password(length=12, characters=None):
  """Generates a random password of the specified length.

  Args:
    length: The length of the password to generate.
    characters: A string of characters to use when generating the password. If
      None, the default character set will be used.

  Returns:
    A random password of the specified length.
  """

  if characters is None:
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+"

  password = ""
  for i in range(length):
    password += random.choice(characters)

  return password


if __name__ == "__main__":
  print("Generated password:", generate_password())
