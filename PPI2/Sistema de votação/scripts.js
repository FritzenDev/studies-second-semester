function submitForm() {
    document.getElementById('registration').classList.add('hidden');
    document.getElementById('voting').classList.remove('hidden');
}

let selectedEmojiElement = null;

function selectEmoji(emojiId) {
    // Remove seleção anterior, se houver
    if (selectedEmojiElement) {
        selectedEmojiElement.classList.remove('selected');
    }
    // Adiciona seleção ao novo emoji
    selectedEmojiElement = document.getElementById(emojiId);
    selectedEmojiElement.classList.add('selected');
}

function submitVote() {
    if (!selectedEmojiElement) {
        alert('Por favor, selecione um emoji para votar.');
        return;
    }
    const emoji = selectedEmojiElement.textContent;
    document.getElementById('result').innerText = `Você votou em: ${emoji}`;
}

function validateForm() {
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const pass = document.getElementById('password').value;

    // Validação do nome (apenas letras, máximo 25 caracteres)
    if (!/^[A-Za-zÀ-ÖØ-ÿ\s]{1,25}$/.test(name)) {
        alert('O nome deve conter apenas letras e ter no máximo 25 caracteres.');
        return false;
    }

    // Validação do email (formato de email)
    if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email)) {
        alert('Por favor, insira um email válido.');
        return false;
    }

    // Validação do CPF (somente números e exatamente 11 dígitos)
    if (!/^[A-Za-z\d]{4}$/.test(pass)) {
        alert('A senha deve conter exatamente 4 caracteres, podendo ser letras ou números.');
        return false;
    }

    // Se todas as validações passaram, redireciona para a aba de votação
    submitForm();
    return false; // Para evitar o envio do formulário
}

document.getElementById('togglePassword').addEventListener('click', function () {
    const passwordField = document.getElementById('password');
    const type = passwordField.getAttribute('type') === 'password' ? 'text' : 'password';
    passwordField.setAttribute('type', type);
    this.textContent = type === 'password' ? '👁️' : '🙈'; // Alterna o ícone
});
