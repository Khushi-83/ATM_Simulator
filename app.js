document.getElementById('atm-form').addEventListener('submit', function(event) {
    event.preventDefault();

    const accountNumber = document.getElementById('account-number').value;
    const amount = document.getElementById('amount').value;
    const action = document.getElementById('action').value;
    let url = '';

    switch (action) {
        case 'check':
            url = `/check_balance/${accountNumber}`;
            break;
        case 'deposit':
            url = `/deposit/${accountNumber}/${amount}`;
            break;
        case 'withdraw':
            url = `/withdraw/${accountNumber}/${amount}`;
            break;
        default:
            document.getElementById('result').innerText = 'Invalid action!';
            return;
    }

    fetch(url)
        .then(response => response.json())
        .then(data => {
            if (data.error) {
                document.getElementById('result').innerText = data.error;
            } else {
                document.getElementById('result').innerText = data.message || `Your balance is: $${data.balance}`;
            }
        })
        .catch(error => {
            document.getElementById('result').innerText = 'Error: ' + error;
        });
});
