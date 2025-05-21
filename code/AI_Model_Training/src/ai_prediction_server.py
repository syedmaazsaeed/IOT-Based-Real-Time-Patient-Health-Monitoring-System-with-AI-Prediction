from fastapi import FastAPI
import joblib
import numpy as np

# Load the trained model and scaler
model = joblib.load('patient_health_model.pkl')
scaler = joblib.load('scaler.pkl')

# Create FastAPI app
app = FastAPI()

# Define POST API to accept sensor data
@app.post("/predict")
async def predict(ecg: float, heart_rate: float, spo2: float, temperature: float):
    # Step 1: Create numpy array from input
    input_data = np.array([[ecg, heart_rate, spo2, temperature]])
    
    # Step 2: Scale the input data
    input_scaled = scaler.transform(input_data)
    
    # Step 3: Make prediction
    prediction = model.predict(input_scaled)
    
    # Step 4: Return prediction
    return {
        "health_status": "Critical" if prediction[0] == 1 else "Normal"
    }
