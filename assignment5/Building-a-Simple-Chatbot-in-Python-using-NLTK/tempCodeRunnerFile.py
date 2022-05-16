import re
import long_response as long

def message_probability(msg,recog_word,single_response=False,required_words=[]):
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
              


def check_all_msg(message):
    highest_prob_list = {}

    # Simplifies response creation / adds it to the dict
    def response(bot_response, list_of_words, single_response=False, required_words=[]):
        nonlocal highest_prob_list
        highest_prob_list[bot_response] = message_probability(message, list_of_words, single_response, required_words)

    # Responses -------------------------------------------------------------------------------------------------------
    response('Hello!', ['hello', 'hi', 'hey', 'sup', 'heyo'], single_response=True)
    response('See you!', ['bye', 'goodbye'], single_response=True)
    response('I\'m doing fine, and you?', ['how', 'are', 'you', 'doing'], required_words=['how'])
    response('You\'re welcome!', ['thank', 'thanks'], single_response=True)
    response('Thank you!', ['i', 'love', 'code', 'palace'], required_words=['code', 'palace'])

    # Longer responses
    response(long.R_ADVICE, ['give', 'advice'], required_words=['advice'])
    response(long.R_EATING, ['what', 'you', 'eat'], required_words=['you', 'eat'])

    best_match = max(highest_prob_list, key=highest_prob_list.get)
    # print(highest_prob_list)
    # print(f'Best match = {best_match} | Score: {highest_prob_list[best_match]}')

    return long.unknown() if highest_prob_list[best_match] < 1 else best_match





def get_response(user_input):
   split_message = re.split(r'\s+|[,;?!.-]\s*',       user_input.lower())
   response = check_all_msg(split_message)
   return response

while True:
    print('BOT: '+ get_response(input('You: ')))