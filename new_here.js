**The things you will find new here!

Statement) In every project we do, we will be learning some new things! In the last project of todo list, we cover a whole lot of basics. Now, it's time to upgrade ourselves!

Here's an overview of the new JavaScript concepts that we'll be using AND LEARNING in the WORDLE game:

jQuery: jQuery is a popular JavaScript library that simplifies working with HTML elements and handling events. It allows us to easily select and manipulate elements in the HTML document.

forEach Loop: We'll use a forEach loop to iterate through arrays and perform actions for each element. In our case, we'll use it to render the word containers and feedback history.

Maps: A map is a data structure that allows us to store key-value pairs. We'll use maps to keep track of letters in the secret word and guessed word for the feedback.

Switch Statements: Switch statements are used for making decisions based on different cases. We'll use switch statements to apply different styles to the letters based on the feedback (correct, exists, or wrong).

Sounds: Sounds make any website more interesting, especially, when it is some game!

API Calls: We'll make an API call to an external service that provides a random word of a specified length. The fetched word will be used as the secret word for the game.

By the end of this course, you'll have a fully functional Wordle game that demonstrates various JavaScript and jQuery concepts, as well as API integration. It's a fun way to enhance your JavaScript skills and create an interactive game to challenge your friends! Happy coding!

-----------------------------------------------------------------------------------------------------------------------------
SOLUTIOn = index.js: $(document).ready(function () {
  let secretWord = "";
  let maxTries = "";
  let chancesLeft = maxTries;
  let guessedWords = [];

  const $wordContainer = $("#word-container");
  const $guessForm = $("#guess-form");
  const $guessInput = $("#guess-input");
  const $submitButton = $("#submitButton");
  const $chancesSpan = $("#chances");
  const $lengthSpan = $("#length");
  const $feedbackDiv = $("#feedback");
  const $historyList = $("#history-list");

  const $startsound = $("#startsound");
  const $endsuccesssound = $("#endsuccesssound");
  const $endfailsound = $("#endfailsound");

  $("#start-button").on("click", function () {
    $(this).prop("disabled", true); // Disable the Start Game button
    $submitButton.prop("disabled", false); // Enable the Submit button
    fetchRandomWord(); // Start the game by fetching the random word
  });

  // Calling the API
  function fetchRandomWord() {
    $startsound[0].play();
    fetch("https://random-word-api.vercel.app/api?words=1&length=5", {
      method: "GET",
    })
      .then((response) => response.json())
      .then((data) => {
        console.log(data);
        secretWord = data[0].toUpperCase();
        maxTries = secretWord.length + 1;
        chancesLeft = maxTries;
        $chancesSpan.text(chancesLeft);
        $lengthSpan.text(secretWord.length);
        $guessInput.attr("maxlength", secretWord.length);
        renderWordContainers();
        console.log("Secret Word: ", secretWord);
      })
      .catch((error) => {
        console.error("Error: ", error.message);
      });
  }

  function renderWordContainers() {
    $wordContainer.empty();
    for (let i = 0; i < secretWord.length; i++) {
      $wordContainer.append(`<span class="letter" id="letter-${i}">?</span>`);
    }
  }

  function checkWordle(guess) {
    const originalWord = secretWord; // Store the original secret word

    let secretLetters = {};
    let guessLetters = {};
    let feedback = guess.split("").map((letter, index) => {
      const correctLetter = originalWord[index];
      if (letter === correctLetter) {
        return "C";
      } else {
        // Count letters in the secret word and guessed word
        secretLetters[correctLetter] = (secretLetters[correctLetter] || 0) + 1;
        guessLetters[letter] = (guessLetters[letter] || 0) + 1;
      }
    });

    // Check for existing letters with matching counts
    feedback.forEach((result, index) => {
      const letter = guess[index];
      if (
        result !== "C" &&
        secretLetters[letter] > 0 &&
        guessLetters[letter] > 0
      ) {
        feedback[index] = "E";
        secretLetters[letter]--;
      } else if (result !== "C") {
        feedback[index] = "W";
      }
    });

    console.log("feedback");
    console.log(feedback);
    console.log(secretLetters);
    console.log(guessLetters);

    return feedback;
  }

  function showFeedback(feedback) {
    feedback.forEach((result, index) => {
      const $letter = $(`#letter-${index}`);
      $letter.removeClass("correct exists wrong");
      switch (result) {
        case "C":
          $letter.addClass("correct");
          break;
        case "E":
          $letter.addClass("exists");
          break;
        case "W":
          $letter.addClass("wrong");
          break;
        default:
          break;
      }
    });
  }

  function renderHistory() {
    $historyList.empty();
    guessedWords.forEach((word, index) => {
      const feedback = checkWordle(word);
      let wordHtml = "";
      word.split("").forEach((letter, index) => {
        let letterClass = "";
        switch (feedback[index]) {
          case "C":
            letterClass = "correct";
            break;
          case "E":
            letterClass = "exists";
            break;
          case "W":
            letterClass = "wrong";
            break;
          default:
            break;
        }
        wordHtml += `<span class="letter ${letterClass}">${letter}</span>`;
      });
      const wordClass = feedback.every((val) => val === "C")
        ? "correct-word"
        : "incorrect-word";
      $historyList.append(`<li class="${wordClass}">${wordHtml}</li>`);
    });
  }

  $guessForm.on("submit", function (event) {
    event.preventDefault();
    const guess = $guessInput.val().toUpperCase();
    if (guess.length === secretWord.length) {
      const feedback = checkWordle(guess);
      showFeedback(feedback);
      guessedWords.push(guess);
      renderHistory();
      chancesLeft--;
      $chancesSpan.text(chancesLeft);

      // Condition for game over
      if (feedback.every((val) => val === "C") || chancesLeft === 0) {
        showResult(feedback);
      }
    } else {
      alert(`Please enter a ${secretWord.length}-letter word.`);
    }
    $guessInput.val("");
  });

  // Shows result on game over
  function showResult(feedback) {
    if (feedback.every((val) => val === "C")) {
      $endsuccesssound[0].play();
      const $resultDiv = $(
        '<div class="result-message">Congratulations! You guessed the word correctly.</div>'
      );
      $resultDiv.hide().appendTo(".container").fadeIn(1000);
    } else {
      $endfailsound[0].play();
      const $resultDiv = $(
        '<div class="result-message">Sorry, you ran out of chances. The correct word was ' +
          secretWord +
          ".</div>"
      );
      $resultDiv.hide().appendTo(".container").fadeIn(1000);
    }

    // Disable form input and submit button after the game is over
    console.log($submitButton);
    console.log($guessInput);

    $guessInput.prop("disabled", true);
    $submitButton.prop("disabled", true);
    $guessForm.off("submit");

    // Clear chances and feedback after the game is over
    $chancesSpan.text("0");
    $feedbackDiv.empty();
  }

  function reloadPage() {
    location.reload();
  }

  // Add event listener to the reload button
  $("#reload-button").on("click", reloadPage);
});

-------------index.html= <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Guess the Word</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <audio 
    id="startsound" 
    src="https://cdn.codechef.com/Learning/startsound.mp3"
    ></audio>
    
    <audio 
    id="endsuccesssound" 
    src="https://cdn.codechef.com/Learning/endsuccesssound.mp3"
    ></audio>
    
    <audio 
    id="endfailsound" 
    src="https://cdn.codechef.com/Learning/endfailsound.mp3"
    ></audio>

    <div class="container">
        <h1>Guess the Word</h1>
        <button id="start-button">Start Game</button>
        <div id="word-container"></div>
        <p>Chances left: <span id="chances">Click On Start Game!</span></p>
        <p>Word Length: <span id="length">Click On Start Game!</span></p>
        <div id="feedback"></div>
        <div id="history-container">
            <!-- <h3>History:</h3> -->
            <ul id="history-list"></ul>
        </div>
        <form id="guess-form">
            <input type="text" id="guess-input" required>
            <button id="submitButton" type="submit">Guess</button>
        </form>
        <!-- Reload Button -->
        <button id="reload-button">Reload Game</button>
    </div>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="index.js"></script>
</body>
</html>

-----------style.css= body {
    font-family: Arial, sans-serif;
    background-color: #f0f0f0;
}

.container {
    max-width: 400px;
    margin: 50px auto;
    background-color: #fff;
    padding: 20px;
    box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
    border-radius: 5px;
    text-align: center;
}

h1 {
    margin-bottom: 20px;
}

#word-container {
    margin-bottom: 20px;
}

#word-container span {
    display: inline-block;
    width: 30px;
    height: 30px;
    line-height: 30px;
    text-align: center;
    background-color: #007bff;
    color: #fff;
    margin-right: 5px;
    border-radius: 5px;
}

form {
    margin-bottom: 10px;
}

#guess-input {
    padding: 8px;
    width: 120px;
    text-transform: uppercase;
}

button {
    padding: 8px 20px;
    background-color: #007bff;
    color: #fff;
    border: none;
    border-radius: 5px;
    cursor: pointer;
}

#chances {
    font-weight: bold;
    color: #007bff;
}

#feedback {
    margin-bottom: 20px;
}

.correct {
    background-color: green;
}

.exists {
    background-color: yellow;
}

.wrong {
    background-color: red;
}

#history-container {
    margin-top: 20px;
}

#history-list {
    list-style: none;
    padding: 0;
}

#history-list li {
    margin-bottom: 5px;
}

/* Styling for the history section */
#history-list li .letter {
    display: inline-block;
    width: 30px;
    height: 30px;
    line-height: 30px;
    text-align: center;
    background-color: #f0f0f0;
    color: #000;
    margin-right: 5px;
    border: 1px solid #007bff;
    border-radius: 5px;
}

#history-list li .letter.correct {
    background-color: green;
}

#history-list li .letter.exists {
    background-color: yellow;
}

#history-list li .letter.wrong {
    background-color: red;
}

#history-list li .letter {
    display: inline-block;
    width: 30px;
    height: 30px;
    line-height: 30px;
    text-align: center;
    background-color: #f0f0f0;
    color: #000;
    margin-right: 5px;
    border: 1px solid #007bff;
    border-radius: 5px;
}

.result-message {
    padding: 10px;
    background-color: #007bff;
    color: #fff;
    border-radius: 5px;
    margin-top: 20px;
}

#start-button {
    margin-bottom: 5px;
}
