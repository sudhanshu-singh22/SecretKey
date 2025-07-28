# 🔐 Secret Key Recovery from Shares

This project solves the problem of reconstructing a **secret integer key** using **Shamir's Secret Sharing** concept. Given multiple representations of a number in different bases, the goal is to determine the original integer that matches all base-value pairs.

---

## 📌 Problem Statement

You are given `k` shares, each representing a number in a certain base. Each share provides:

- A base (e.g., base 2, base 10, base 16)
- A string that represents the number in that base

The task is to **recover the original integer** `x` such that:

