import time

def countdown(t):
	
	while t:
		mins, secs = divmod(t, 60)
		timer = 'Tersisa: {:02d}:{:02d}'.format(mins, secs)
		print(timer, end="\r")
		time.sleep(1)
		t -= 1
	
	print('Waktu Habis')

t = input("Masukkan waktu dalam satuan detik: ")

countdown(int(t))