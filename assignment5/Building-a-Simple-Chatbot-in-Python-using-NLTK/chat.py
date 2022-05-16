import re
import long_response as long

def msg_prob(msg,recog_word,single_response=False,required_words=[]):
    msg_certanity=0
    has_required_words=True
    
    for words in msg:
        if(words in recog_word):
            msg_certanity+=1
    
    percentage = float(msg_certanity)/float(len(recog_word))

    for word in required_words:
        if word not in msg :
            has_required_words=False
            break


    if has_required_words or single_response:
        return int(percentage*100)
    else:
        return 0
              


def check_all_msg(msg):
    highest_prob = {}
    
    def response(bot_response,list_words,single_response=False,required_word=[]):
        nonlocal highest_prob
        highest_prob[bot_response] = msg_prob(msg,list_words,single_response,required_word)

    response('Hello!',['hello','hey','sup','hola'],single_response=True)

    response('See you soon!!',['bye','goodbye','tata'],single_response=True);

    response('I am doing fine',['how','are','you'],required_word=['how'])

    response('Your Welcome!!',['thank','thanks','thank','you'],single_response=True)

    response(long.R_ADVICE, ['give', 'advice'], required_word=['advice'])

    response(long.R_EATING, ['what', 'you', 'eat'], required_word=['you', 'eat'])

    best_match=max(highest_prob,key=highest_prob.get)

    print(highest_prob)

    return long.unknown() if highest_prob[best_match]<1 else best_match



def get_response(user_input):
   split_message = re.split(r'\s+|[,;?!.-]\s*',       user_input.lower())
   response = check_all_msg(split_message)
   return response

while True:
    print('BOT: '+ get_response(input('You: ')))