import random
from urllib import response


R_EATING = "I don't like eating anything because I'm a bot obviously!"
R_ADVICE = "If I were you, I would go to the internet and type exactly what you wrote there!"

def unknown():
    response = ['Could you rephrasee','.....','what does it mean?','sounds about right'][random.randrange(4)]

    return response